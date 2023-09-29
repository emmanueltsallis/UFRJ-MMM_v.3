# MMM_Monte Carlo
Monte Carlo experiment with Multisectoral Micro-Macro Model Version 3.6 (Finance Augmented)

## RESULTADOS

Para comparar os resultados de cada política, vamos nos concentrar em três indicadores econômicos-chave: inflação do CPI, crescimento econômico anual e utilização da capacidade. Vamos examinar as médias, medianas, desvio padrão, valores mínimos e máximos para cada indicador em cada política.

Política 1: Regra de Taylor e Meta de Superávit Primário
- Média da Inflação do CPI: 0,018
- Mediana da Inflação do CPI: 0,0173
- Desvio Padrão da Inflação do CPI: 0,00556
- Mínimo da Inflação do CPI: -0,000802
- Máximo da Inflação do CPI: 0,0399

- Média do Crescimento Anual: 0,026
- Mediana do Crescimento Anual: 0,0243
- Desvio Padrão do Crescimento Anual: 0,0284
- Mínimo do Crescimento Anual: -0,0679
- Máximo do Crescimento Anual: 0,13

- Média da Utilização da Capacidade: 0,921
- Mediana da Utilização da Capacidade: 0,924
- Desvio Padrão da Utilização da Capacidade: 0,0198
- Mínimo da Utilização da Capacidade: 0,855
- Máximo da Utilização da Capacidade: 0,96

Política 3: Regra de Taylor e Política Fiscal Não-Restritiva
- Média da Inflação do CPI: 0,018
- Mediana da Inflação do CPI: 0,0183
- Desvio Padrão da Inflação do CPI: 0,00362
- Mínimo da Inflação do CPI: 0,0061
- Máximo da Inflação do CPI: 0,0287

- Média do Crescimento Anual: 0,0286
- Mediana do Crescimento Anual: 0,0282
- Desvio Padrão do Crescimento Anual: 0,0191
- Mínimo do Crescimento Anual: -0,023
- Máximo do Crescimento Anual: 0,093

- Média da Utilização da Capacidade: 0,926
- Mediana da Utilização da Capacidade: 0,927
- Desvio Padrão da Utilização da Capacidade: 0,0118
- Mínimo da Utilização da Capacidade: 0,881
- Máximo da Utilização da Capacidade: 0,959

Política 4: Taxa de Juros Fixa e Política Fiscal Não-Restritiva
- Média da Inflação do CPI: 0,0172
- Mediana da Inflação do CPI: 0,0168
- Desvio Padrão da Inflação do CPI: 0,00406
- Mínimo da Inflação do CPI: 0,00605
- Máximo da Inflação do CPI: 0,0318

- Média do Crescimento Anual: 0,0265
- Mediana do Crescimento Anual: 0,0263
- Desvio Padrão do Crescimento Anual: 0,0194
- Mínimo do Crescimento Anual: -0,0389
- Máximo do Crescimento Anual: 0,09

- Média da Utilização da Capacidade: 0,92
- Mediana da Utilização da Capacidade: 0,924
- Desvio Padrão da Utilização da Capacidade: 0,0185
- Mínimo da Utilização da Capacidade: 0,847
- Máximo da Utilização da Capacidade: 0,963

Comparação:
1. Em termos de inflação do CPI, a Política 3 (Regra de Taylor e Política Fiscal Não-Restritiva) tem o desvio padrão mais baixo e a taxa de inflação mediana mais alta, indicando uma inflação relativamente estável em comparação com as outras políticas.

2. Em termos de crescimento anual, a Política 3 também tem as maiores taxas médias e medianas de crescimento, sugerindo que ela pode levar a um melhor crescimento econômico.

3. Em relação à utilização da capacidade, a Política 3 tem os valores médios e medianos mais altos, indicando que a economia opera mais próxima de sua capacidade máxima sob essa política.

4. A Política 4 (Taxa de Juros Fixa e Política Fiscal Não-Restritiva) geralmente apresenta resultados semelhantes aos da Política 1 (Regra de Taylor e Meta de Superávit Primário), mas com uma inflação ligeiramente mais baixa e um crescimento econômico um pouco maior.

Em geral, a Política 3 parece ter resultados econômicos mais favoráveis em termos de estabilidade da inflação, crescimento econômico e utilização da capacidade em comparação com as outras políticas. A Política 4 também mostra resultados positivos, enquanto a Política 1 tem um crescimento econômico relativamente mais baixo e inflação ligeiramente menos estável.

## WHAT'S NEW?

Introduction of Banking System
* N number of Bank Agents
* Basileia-type Regulatory Rule
* Financial Fragility Sensitivity

Endogeneization of Firm's and Classes Financial Decisions
* Desired Debt Rate
* Liquidity Preference

Introduction of Financial Costs to Firms

Introduction of Interest Rate Structure
* Basic Interest Rate Following Possible Monetary Policy Rules
* Deposits Spread
* Short-Term Loans Spread
* Long-Term Loans Spread
* Individual Risk-Premium

Introduction of Some Analysis Variables
* Firm's Financial Positions (Hedge, Speculative, Ponzi)
* Bankrupt events counter
* Bank and Financial Sector Variables

For more information on previous versions: <https://thttnn.github.io/MMM_CORE/>

### BANKING SYSTEM:
The banking system is composed by a pre-determined number of banks, which collect deposits from firms and income classes and provide loans to them. 
The number of banks is fixed and they all start equally.
Firm-bank relationships are determined randomly at the beginning of the simulation run, but after, the probability is weighted by bank's market-share.
Firm-bank relationships are fixed for the simulation run.
Income classes deposits, interest and loans are distributed to banks by market-share.
Banks have a limit to total credit based on basileia-type regulatory rule, net worth and individual financial fragility sensitivities.
However, credit rationing affects bank's competitiveness negativelly, as well as defaulted loans. 

### INTEREST RATE STRUCTURE:
Banks set deposits and short-term interest rates by simply applying a markup or markdown on basis interest rate.
Long-term interest rates are adjusted by bank's market-share. Therefore, the higher the concentration, higher is the average long-term rate.
Basic Interest Rate depends on the monetary policy rule.

### FIRM'S FINANCIAL DECISIONS:
Firms can adjust (or not) desired debt rate and liquidity preference (as a share of capital) based on net profits growth.
Firms can adjust extra amortization (or not) based on current and desired debt rate.
Firms can incorporate (or not) financial costs to unit variable cost if current debt rate is higher than desired.
Income classes can also adjust desired debt rate and liquidity preference based on net income growth.


