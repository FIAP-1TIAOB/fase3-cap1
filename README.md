# FIAP - Faculdade de Informática e Administração Paulista

<p align="center">
<a href= "https://www.fiap.com.br/"><img src="assets/logo-fiap.png" alt="FIAP - Faculdade de Informática e Admnistração Paulista" border="0" width=40% height=40%></a>
</p>

<br>

# FarmTech Solutions - Colheita de Dados e Insights (Fase 3)

## Grupo 84

## 👨‍🎓 Integrantes: 
- <a href="https://www.linkedin.com/company/inova-fusca">Milton Akira Fukuhara</a>
- <a href="https://www.linkedin.com/company/inova-fusca">Samyr de Souza Pereira</a>
- <a href="https://www.linkedin.com/company/inova-fusca">Antonio Filipe de Souza Branco</a> 
- <a href="https://www.linkedin.com/company/inova-fusca">Albert Oliveira Ribeiro</a> 
- <a href="https://www.linkedin.com/in/vinicius-adati/">Vinicius Seiti Adati</a>

## 👩‍🏫 Professores:
### Tutor(a) 
- <a href="https://www.linkedin.com/company/inova-fusca">Sabrina Otoni</a>
### Coordenador(a)
- <a href="https://www.linkedin.com/company/inova-fusca">André Godoi Chiovato</a>

## 📜 Descrição

Na terceira fase de desenvolvimento da Startup **FarmTech Solutions**, evoluímos da coleta física de dados (IoT) para o armazenamento estruturado e análise visual. O objetivo desta etapa foi garantir que o histórico de monitoramento da cultura de Soja (umidade, pH, NPK e status da bomba) gerado pelo ESP32 não fosse perdido, estabelecendo uma fundação sólida de dados para a tomada de decisões no agronegócio.

Para a **Entrega Obrigatória**, realizamos a carga e modelagem dos dados dos sensores (`dados_farmtech_sensor (1).csv`) em um Banco de Dados Relacional da Oracle, executando as consultas SQL necessárias no Oracle SQL Developer para validação da integridade das informações.

**Programa Ir Além (Opcional 1 - Dashboard em Python):** Adicionalmente, desenvolvemos uma aplicação web interativa utilizando a biblioteca Streamlit. A dashboard lê a base de dados em tempo real e exibe as métricas de solo e irrigação. Para garantir uma interface técnica, limpa e de alta performance, o gráfico temporal de umidade foi configurado para ocultar os marcadores de dados por padrão, exibindo os detalhes pontuais apenas na interação (hover) do usuário. O sistema também inclui alertas lógicos que sugerem ações de irrigação baseadas no nível crítico de umidade.

**Demonstração em Vídeo:** [Insira o Link do seu Vídeo Não Listado do YouTube Aqui]

## 📁 Estrutura de pastas

Dentre os arquivos e pastas presentes na raiz do projeto, definem-se:

- <b>.github</b>: Arquivos de configuração específicos do GitHub que ajudam a gerenciar e automatizar processos no repositório.
- <b>assets</b>: Arquivos de mídia e evidências visuais, como os prints da consulta no Oracle SQL Developer (`print_oracle.png`) e da interface da aplicação web (`print_dashboard.png`).
- <b>config</b>: Arquivos de configuração usados para definir parâmetros e ajustes do projeto.
- <b>document</b>: Documentos do projeto que as atividades poderão pedir. 
- <b>scripts</b>: Scripts auxiliares para tarefas específicas do projeto.
- <b>src</b>: Todo o código-fonte criado para o desenvolvimento do projeto. Nesta fase, contém o script da dashboard (`app.py`), a base de dados (`dados_farmtech_sensor (1).csv`) e o código C++ de legado da Fase 2 (`sketch.ino`).
- <b>README.md</b>: Arquivo que serve como guia e explicação geral sobre o projeto (o mesmo que você está lendo agora).

## 🔧 Como executar o código

Para visualizar a Dashboard analítica em Python (Streamlit) na sua máquina local, siga os passos:

1. Certifique-se de ter o Python instalado em sua máquina.
2. Clone este repositório do GitHub.
3. Abra o terminal na raiz do projeto e instale as bibliotecas necessárias executando:
   ```bash
   pip install streamlit pandas plotly
