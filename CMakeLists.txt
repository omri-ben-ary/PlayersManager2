cmake_minimum_required(VERSION 3.0)
project(wet2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wet2 main.cpp UnionFindNode.cpp UnionFindNode.h UnionFind.cpp UnionFind.h AVLTree.cpp AVLTree.h EmptyNode.cpp EmptyNode.h LevelNode.cpp LevelNode.h Node.cpp Node.h Player.cpp Player.h RankTree.cpp RankTree.h TreeExceptions.cpp TreeExceptions.h PlayersManager.cpp PlayersManager.h HashTable.cpp HashTable.h HashTableExceptions.cpp HashTableExceptions.h PlayersManagerExceptions.cpp PlayersManagerExceptions.h library2.cpp library2.h)
