//
// Created by sciphilib on 4/30/2022.
//

#ifndef ALGO_ARRAYLISTS_H
#define ALGO_ARRAYLISTS_H


#include <string>
#include <utility>

class ArrayLists {
public:
    enum english_letters {
        A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, ALL
    };
    struct List {
        struct Node {
            Node *next;
            std::string firstname;
            std::string secondname;
            Node();
            ~Node();
        };
        Node *head;
        Node *tail;
        void add(const std::string &fn, const std::string &sn);
        void print() const;
        List();
        ~List();
    };
private:
    List* letters[26]; // an array for all english letters
public:
    ArrayLists() = default;
    ~ArrayLists();
    void add(const std::string &fn, const std::string &sn);
    void print() const;
};


#endif //ALGO_ARRAYLISTS_H
