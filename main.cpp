#include <chrono>
#include <iostream>

int main() {
  const size_t discard = 10 * 1000 * 1000;
  const size_t profile = 10 * 1000 * 1000;
  for (size_t i = 0; i < discard; ++i) {
    std::chrono::steady_clock::now();
  }
  const auto a = std::chrono::steady_clock::now();
  for (size_t i = 0; i < profile; ++i) {
    std::chrono::steady_clock::now();
  }
  const auto b = std::chrono::steady_clock::now();
  const std::chrono::duration<double, std::nano> delta = b - a;
  const auto speed = delta.count() / static_cast<double>(profile);
  std::cout << speed << " ns." << '\n';
}
