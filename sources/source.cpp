// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru
#include <chrono>
#include <iostream>

int main() {
  /*
   Intel Core i7-8550U
   L1=256
   L2=1024
   L3=8192
  */

  size_t experimnets_number = 1000;

  // 1/2 L1
  {
    std::srand(std::time(nullptr));
    size_t size = 32768;
    int* array = new int[size];
    // filling
    for (size_t i = 0; i < size; ++i) array[i] = std::rand() % 100000;

    // experiment

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // direct
    auto start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_direct = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // back
    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = size; i > 0; --i) ++array[i];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_back = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // random

    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[std::rand() % size];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_random = end - start;

    delete[] array;

    // answer

    std::cout << "-------------------------------------------------------------"
              << std::endl
              << "Investigation: 1/2 L1 (buffer size=" << size << ")"
              << std::endl
              << "-Number of experiments: " << experimnets_number << std::endl
              << "-Travel Variant:" << std::endl
              << "--Straight:" << std::endl
              << "---Duration: " << duration_direct.count() << std::endl
              << "--Back:" << std::endl
              << "---Duration: " << duration_back.count() << std::endl
              << "--Random:" << std::endl
              << "---Duration: " << duration_random.count() << std::endl;
  }

  // L1
  {
    std::srand(std::time(nullptr));
    size_t size = 65536;
    int* array = new int[size];
    // filling
    for (size_t i = 0; i < size; ++i) array[i] = std::rand() % 100000;

    // experiment

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // direct
    auto start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_direct = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // back
    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = size; i > 0; --i) ++array[i];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_back = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // random

    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[std::rand() % size];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_random = end - start;

    delete[] array;

    // answer

    std::cout << "-------------------------------------------------------------"
              << std::endl
              << "Investigation:L1 (buffer size=" << size << ")" << std::endl
              << "-Number of experiments: " << experimnets_number << std::endl
              << "-Travel Variant:" << std::endl
              << "--Straight:" << std::endl
              << "---Duration: " << duration_direct.count() << std::endl
              << "--Back:" << std::endl
              << "---Duration: " << duration_back.count() << std::endl
              << "--Random:" << std::endl
              << "---Duration: " << duration_random.count() << std::endl;
  }

  // L2
  {
    std::srand(std::time(nullptr));
    size_t size = 262144;
    int* array = new int[size];
    // filling
    for (size_t i = 0; i < size; ++i) array[i] = std::rand() % 100000;

    // experiment

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // direct
    auto start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_direct = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // back
    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = size; i > 0; --i) ++array[i];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_back = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // random

    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[std::rand() % size];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_random = end - start;

    delete[] array;

    // answer

    std::cout << "-------------------------------------------------------------"
              << std::endl
              << "Investigation:L2 (buffer size=" << size << ")" << std::endl
              << "-Number of experiments: " << experimnets_number << std::endl
              << "-Travel Variant:" << std::endl
              << "--Straight:" << std::endl
              << "---Duration: " << duration_direct.count() << std::endl
              << "--Back:" << std::endl
              << "---Duration: " << duration_back.count() << std::endl
              << "--Random:" << std::endl
              << "---Duration: " << duration_random.count() << std::endl;
  }

  // L3
  {
    std::srand(std::time(nullptr));
    size_t size = 2097152;
    int* array = new int[size];
    // filling
    for (size_t i = 0; i < size; ++i) array[i] = std::rand() % 100000;

    // experiment

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // direct
    auto start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_direct = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // back
    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = size; i > 0; --i) ++array[i];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_back = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // random

    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[std::rand() % size];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_random = end - start;

    delete[] array;

    // answer

    std::cout << "-------------------------------------------------------------"
              << std::endl
              << "Investigation:L3 (buffer size=" << size << ")" << std::endl
              << "-Number of experiments: " << experimnets_number << std::endl
              << "-Travel Variant:" << std::endl
              << "--Straight:" << std::endl
              << "---Duration : " << duration_direct.count() << std::endl
              << "--Back:" << std::endl
              << "---Duration: " << duration_back.count() << std::endl
              << "--Random:" << std::endl
              << "---Duration: " << duration_random.count() << std::endl;
  }

  // 3/2 L3
  {
    std::srand(std::time(nullptr));
    size_t size = 3145728;
    int* array = new int[size];
    // filling
    for (size_t i = 0; i < size; ++i) array[i] = std::rand() % 100000;

    // experiment

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // direct
    auto start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[i];
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_direct = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // back
    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = size; i > 0; --i) ++array[i];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_back = end - start;

    // warming up
    for (size_t i = 0; i < size; i += 16) ++array[i];

    // random

    start = std::chrono::steady_clock::now();
    for (size_t j = 0; j < experimnets_number; ++j) {
      for (size_t i = 0; i < size; ++i) ++array[std::rand() % size];
    }
    end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_random = end - start;

    delete[] array;

    // answer

    std::cout << "-------------------------------------------------------------"
              << std::endl
              << "Investigation:L3 (buffer size=" << size << ")" << std::endl
              << "-Number of experiments: " << experimnets_number << std::endl
              << "-Travel Variant:" << std::endl
              << "--Straight:" << std::endl
              << "---Duration : " << duration_direct.count() << std::endl
              << "--Back:" << std::endl
              << "---Duration: " << duration_back.count() << std::endl
              << "--Random:" << std::endl
              << "---Duration: " << duration_random.count() << std::endl;
  }

  return 0;
}
