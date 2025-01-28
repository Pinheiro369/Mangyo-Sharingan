
# Mangyo Sharingan

### Descrição
O **Mangyo Sharingan** é uma ferramenta de pentest criada para executar ataques de negação de serviço (DoS) em redes. Seu objetivo principal é auxiliar profissionais de segurança em testes autorizados de infraestrutura, ajudando a identificar vulnerabilidades.

O script utiliza threads para enviar pacotes de forma descentralizada e constante, sobrecarregando a rede de destino e testando sua resiliência.

### Aviso Legal
Este script é exclusivamente para **fins educacionais** e deve ser utilizado apenas em redes sob sua propriedade ou com autorização explícita.  
**O uso indevido para atividades ilegais é estritamente proibido.**  
O autor não se responsabiliza por quaisquer consequências decorrentes do uso inadequado deste código.

### Pré-requisitos
- **Compilador C++** (como o GCC) instalado no sistema.
- Permissão para realizar testes na rede de destino.
- Conhecimento básico de redes e segurança cibernética.

### Como Funciona
1. O script solicita o IP do alvo, a porta e o número de threads desejadas.
2. Gera pacotes de dados aleatórios (1 KB cada).
3. Envia os pacotes para o IP e porta especificados, utilizando threads para maximizar a carga.
4. Exibe mensagens coloridas no terminal para indicar o progresso do ataque e status das conexões.

### Configuração e Uso
1. **Baixe o código:**  
   [Mangyo_Sharingan.cpp](sandbox:/mnt/data/Mangyo_Sharingan.cpp)

2. **Compile o código usando o GCC:**
   ```bash
   g++ mangyo_sharingan.cpp -o mangyo_sharingan -std=c++11 -pthread
   ```

3. **Execute o script:**
   ```bash
   ./mangyo_sharingan
   ```

4. **Informe os dados solicitados no terminal:**
   - IP do alvo: Endereço de destino (por exemplo, `192.168.0.1`).
   - Porta do alvo: Porta a ser atacada (por exemplo, `80`).
   - Número de threads: Quantidade de threads para envio de pacotes (por exemplo, `10`).

### Exemplo de Uso
Ao executar o script, você verá uma interface parecida com a seguinte:

```plaintext
============================================
         AVISO LEGAL - MANGYO SHARINGAN
============================================
Este script foi criado unicamente para fins educacionais...
============================================

Digite o IP do alvo: 192.168.0.1
Digite a porta do alvo: 80
Digite o número de threads: 10

//======================================//
||      Mangyo Sharingan Ativando...   ||
\======================================\

[INFO] Iniciando ataque contra 192.168.0.1:80 com 10 threads...
[INFO] Thread 1 iniciada.
[INFO] Thread 2 iniciada.
[Pacote Enviado] Alvo: 192.168.0.1:80
[Pacote Enviado] Alvo: 192.168.0.1:80
```

Para interromper o ataque, use `Ctrl + C`.

### Funções Principais
- `send_packets(ip, port)`: Envia pacotes de 1 KB para o IP e porta especificados.
- `start_attack(ip, port, threads)`: Gerencia a criação de múltiplas threads para executar `send_packets` de forma simultânea.
- Mensagens coloridas (ANSI): 
  - Vermelho para erros e avisos.
  - Verde para mensagens de sucesso.
  - Azul para informações gerais.

### Mensagens Importantes
- **"Mangyo Sharingan Ativando..."**: Indica que o script iniciou corretamente.
- **"[INFO] Thread X iniciada"**: Mostra o progresso das threads criadas.
- **"[Pacote Enviado]"**: Informa que um pacote foi enviado com sucesso.
- **"[Erro]"**: Exibe problemas durante o envio.

### Boas Práticas
1. **Teste apenas em redes autorizadas**.
2. Use o script para analisar a resiliência de sua rede e identificar melhorias.
3. Evite utilizar configurações muito altas (como centenas de threads) sem necessidade.

### Requisitos Técnicos
- **Bibliotecas nativas utilizadas:**
  - `iostream`: Para entrada e saída no console.
  - `thread`: Para criar múltiplas threads.
  - `cstdlib` e `cstring`: Para manipulação de strings e buffers.
  - `netinet/in.h`, `sys/socket.h`, `unistd.h`: Para manipulação de redes e sockets.
  - `random`: Para gerar pacotes aleatórios.

### Saída Final
Ao finalizar o ataque (usando `Ctrl + C`), o script exibe:

```plaintext
============================================
                ATAQUE FINALIZADO
============================================
Obrigado por usar o Mangyo Sharingan de forma responsável!
```

### Licença
Este script é distribuído sob a licença MIT. Sinta-se livre para estudar e modificá-lo, mas use-o de forma responsável.
