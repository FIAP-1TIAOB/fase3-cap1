import streamlit as st
import pandas as pd
import plotly.express as px

st.set_page_config(page_title="FarmTech Solutions", layout="wide")
st.title("🌱 Dashboard FarmTech - Monitoramento Inteligente")

try:
    # sep=None e engine='python' forçam o Pandas a descobrir se o CSV usa vírgula ou ponto e vírgula
    df = pd.read_csv("dados_farmtech_sensor (1).csv", sep=None, engine='python')
    
    # Limpeza de segurança: remove espaços em branco invisíveis e força tudo para MAIÚSCULO
    df.columns = df.columns.str.strip().str.upper()
    
    st.subheader("Status Atual da Plantação")
    col1, col2, col3 = st.columns(3)
    
    ultima_umidade = df['UMIDADE_SOLO'].iloc[-1]
    ultimo_ph = df['PH'].iloc[-1]
    bomba_ligada = df['BOMBA_LIGADA'].iloc[-1]
    
    col1.metric("Umidade do Solo", f"{ultima_umidade}")
    col2.metric("Nível de pH", f"{ultimo_ph}")
    # Trata a exibição da bomba independentemente se o banco salvou como True/False ou 1/0
    status_bomba = "LIGADA" if bomba_ligada in [True, 1, 'True', 'TRUE'] else "DESLIGADA"
    col3.metric("Status da Bomba", status_bomba)
    
    st.divider()

    st.subheader("Evolução das Métricas")
    
    fig_umidade = px.line(df, x=df.index, y='UMIDADE_SOLO', title="Histórico de Umidade")
    # Mantendo os marcadores de dados ocultos por padrão para um visual analítico e limpo
    fig_umidade.update_traces(mode='lines', hovertemplate="Leitura: %{x}<br>Umidade: %{y}")
    st.plotly_chart(fig_umidade, use_container_width=True)
    
    st.subheader("🤖 Sugestões do Sistema")
    if ultima_umidade < 4000:
        st.warning("Umidade baixa detectada. O sistema ativará a irrigação caso não haja previsão de chuva.")
    else:
        st.success("Níveis de umidade adequados. Irrigação suspensa.")

except FileNotFoundError:
    st.error("Arquivo CSV não encontrado. Verifique se o nome está correto na pasta.")
except KeyError as e:
    # Se ainda der erro, isso vai imprimir as colunas reais na tela para descobrirmos o nome exato
    st.error(f"Erro ao encontrar a coluna. Colunas disponíveis no seu CSV: {list(df.columns)}")