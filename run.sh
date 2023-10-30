clang++ -std=c++17 -Wall -Wextra -Wshadow -g -fsanitize=address,undefined $1 && ./a.out
