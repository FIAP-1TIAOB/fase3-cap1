# 🌱 FarmTech Solutions - Fase 3: Colheita de Dados e Insights

**Equipe de Desenvolvimento:**
- Milton Akira Fukuhara - RM569837 
- Samyr de Souza Pereira - RM573294
- Antonio Filipe de Souza Branco - RM573837 
- Albert Oliveira Ribeiro - RM571521
- Vinicius Seiti Adati - RM568948


## 📋 Sobre o Projeto
A FarmTech Solutions é uma simulação de startup voltada para o agronegócio. Nesta fase do projeto, consolidamos os dados coletados pelo nosso sistema IoT (desenvolvido na Fase 2 com ESP32) para monitoramento de uma plantação de soja. O objetivo principal foi migrar essas leituras físicas para um Banco de Dados Relacional estruturado e, como passo adicional, criar uma interface visual analítica para a tomada de decisão.

## 🏗️ Estrutura do Repositório
* `/src`: Contém os códigos-fonte do projeto.
  * `sketch.ino`: Código C++ de monitoramento via ESP32 (Fase 2).
  * `app.py`: Código Python da Dashboard interativa (Streamlit).
  * `dados_farmtech_sensor.csv`: Base de dados gerada pelos sensores.
* `/assets`: Contém as evidências visuais (prints) do banco de dados e da dashboard.

---

## 💾 Entrega Obrigatória: Banco de Dados Oracle

Os dados simulados de umidade, pH e acionamento da bomba d'água foram importados com sucesso para o banco de dados da FIAP usando o Oracle SQL Developer.

**Passos realizados:**
1. Conexão estabelecida com o host `oracle.fiap.com.br`.
2. Importação do arquivo `src/dados_farmtech_sensor.csv` através da ferramenta de importação de dados.
3. Execução da consulta `SELECT * FROM sensores;` para validar a integridade das linhas e colunas.

---

## 🚀 Programa Ir Além: Dashboard em Python

Para agregar valor aos dados armazenados, desenvolvemos uma Dashboard interativa utilizando a biblioteca **Streamlit**. 

A aplicação lê o histórico de monitoramento e exibe:
* Métricas em tempo real (Umidade, pH e Status da Bomba d'água).
* Gráfico de evolução temporal contínuo (com os marcadores de dados ocultos por padrão, priorizando a fluidez e limpeza visual).
* Sistema de alertas automatizado para sugestão de irrigação baseado nos níveis críticos da cultura de soja.


Para executar a dashboard localmente:
```bash
pip install streamlit pandas plotly
python -m streamlit run src/app.py
