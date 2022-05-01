//
// Created by sciphilib on 4/30/2022.
//

#include <iostream>
#include "ArrayLists.h"

//------------------------------List--------------------------------------//

ArrayLists::List::~List() {
    Node *tmp;
    while (head != nullptr)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

void ArrayLists::List::add(const std::string &fn, const std::string &sn) {
    Node *node = new Node();
    node->firstname = fn;
    node->secondname = sn;

    if (head && tail) {
        tail->next = node;
        tail = node;
    }
    else {
        head = node;
        tail = node;
    }
    tail->next = nullptr;
}

void ArrayLists::List::print() const {
    Node *element;
    if (head) {
        element = head;
        while (element) {
            std::cout << element->firstname << ' ' << element->secondname << " ";
            element = element->next;
        }
    }
    else
    {
        std::cout << "list is empty.";
        return;
    }
}

//------------------------------ArrayLists--------------------------------------//

ArrayLists::ArrayLists(const ArrayLists &arrayList) {
    List::Node *node;
    for (int i = 0; i < 26; ++i)
    {
        if (arrayList.letters[i])
        {
            List *list = new List();
            node = arrayList.letters[i]->head;

            while (node)
            {
                list->add(node->firstname, node->secondname);
                node = node->next;
            }
            letters[i] = list;
        }
        else
            letters[i] = nullptr;
    }
}

ArrayLists::english_letters convertFromCharToEnum(char letter);

void ArrayLists::add(const std::string &fn, const std::string &sn) {
    auto letter = convertFromCharToEnum(static_cast<char>(std::toupper(static_cast<unsigned char>(sn[0]))));

    if (letters[letter] == nullptr)
    {
        auto *list = new List();
        letters[letter] = list;
    }
    letters[letter]->add(fn, sn);
}

ArrayLists::~ArrayLists() {
    for (auto &i:letters) {
            delete i;
    }
}

char convertFromEnumToChar(int number);

void ArrayLists::print() const {
    for (int i = 0; i < 26; ++i)
    {
        std::cout << convertFromEnumToChar(i) << ": ";
        if (letters[i])
            letters[i]->print();
        std::cout << '\n';
    }
}

ArrayLists &ArrayLists::operator=(const ArrayLists &arrayList)
{
    if (this == &arrayList)
        return *this;

    List::Node *node;
    for (int i = 0; i < 26; ++i)
    {
        if (arrayList.letters[i])
        {
            delete letters[i];
            List *list = new List();
            node = arrayList.letters[i]->head;

            while (node)
            {
                list->add(node->firstname, node->secondname);
                node = node->next;
            }
            letters[i] = list;
        }
    }

    return *this;
}


ArrayLists::english_letters convertFromCharToEnum(char letter)
{
    switch (letter) {
        case 'A':
            return ArrayLists::english_letters::A;
        case 'B':
            return ArrayLists::english_letters::B;
        case 'C':
            return ArrayLists::english_letters::C;
        case 'D':
            return ArrayLists::english_letters::D;
        case 'E':
            return ArrayLists::english_letters::E;
        case 'F':
            return ArrayLists::english_letters::F;
        case 'G':
            return ArrayLists::english_letters::G;
        case 'H':
            return ArrayLists::english_letters::H;
        case 'I':
            return ArrayLists::english_letters::I;
        case 'J':
            return ArrayLists::english_letters::J;
        case 'K':
            return ArrayLists::english_letters::K;
        case 'L':
            return ArrayLists::english_letters::L;
        case 'M':
            return ArrayLists::english_letters::M;
        case 'N':
            return ArrayLists::english_letters::N;
        case 'O':
            return ArrayLists::english_letters::O;
        case 'P':
            return ArrayLists::english_letters::P;
        case 'Q':
            return ArrayLists::english_letters::Q;
        case 'R':
            return ArrayLists::english_letters::R;
        case 'S':
            return ArrayLists::english_letters::S;
        case 'T':
            return ArrayLists::english_letters::T;
        case 'U':
            return ArrayLists::english_letters::U;
        case 'V':
            return ArrayLists::english_letters::V;
        case 'W':
            return ArrayLists::english_letters::W;
        case 'X':
            return ArrayLists::english_letters::X;
        case 'Y':
            return ArrayLists::english_letters::Y;
        case 'Z':
            return ArrayLists::english_letters::Z;
        default:
            return ArrayLists::ALL;
    }
}

char convertFromEnumToChar(int number)
{
    switch (number) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';
        case 8:
            return 'I';
        case 9:
            return 'J';
        case 10:
            return 'K';
        case 11:
            return 'L';
        case 12:
            return 'M';
        case 13:
            return 'N';
        case 14:
            return 'O';
        case 15:
            return 'P';
        case 16:
            return 'Q';
        case 17:
            return 'R';
        case 18:
            return 'S';
        case 19:
            return 'T';
        case 20:
            return 'U';
        case 21:
            return 'V';
        case 22:
            return 'W';
        case 23:
            return 'X';
        case 24:
            return 'Y';
        case 25:
            return 'Z';
        default:
            return '0';
    }
}

