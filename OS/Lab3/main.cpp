#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

const int NUM_PHILOSOPHERS = 5;
std::mutex forks[NUM_PHILOSOPHERS];
std::mutex console_mutex;

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (true) {
        
        // Философ размышляет
        std::cout << "Philosopher " << id << " is thinking." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Задержка 0.5 секунды

        // Философ голоден, пытается взять вилки
        {
            std::unique_lock<std::mutex> left_lock(forks[left_fork]);
            std::unique_lock<std::mutex> right_lock(forks[right_fork]);

            // Философ ест спагетти
            std::cout << "Philosopher " << id << " is eating." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Задержка 1 секунда
        }

        // Философ освобождает вилки и начинает размышлять снова
        std::cout << "Philosopher " << id << " has finished eating." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Задержка 0.5 секунды
    }
}

int main() {
    std::thread philosophers[NUM_PHILOSOPHERS];

    // Создаем процессы философов
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    // Ждем завершения работы философов
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}