#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct Mahasiswa {
    string NIM;
    double Nilai_UTS;
    double Nilai_UAS;
    Mahasiswa* next;
};

int jml_node = 0;

Mahasiswa* CREATE_NODE(string NIM, double Nilai_UTS, double Nilai_UAS);

void ShowLIST(Mahasiswa* NODE_Penunjuk);

void InsertFirst(Mahasiswa** H_NODE, string NIM, double Nilai_UTS, double Nilai_UAS);

void InsertLast(Mahasiswa** H_NODE, string NIM, double Nilai_UTS, double Nilai_UAS);

void DeleteFirst(Mahasiswa** H_NODE);

void DeleteLast(Mahasiswa** H_NODE);

int main() {
    Mahasiswa* HEAD_NODE = NULL;
    string NIM;
    double Nilai_UTS, Nilai_UAS;
    int pilih;

    do {
        system("cls");

        cout << "Perintah pada Linked List:" << endl;
        cout << "-----------------------------" << endl;
        cout << "1. Insert First" << endl;
        cout << "2. Insert Last" << endl;
        cout << "3. Delete First" << endl;
        cout << "4. Delete Last" << endl;
        cout << "5. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Current List :" << endl;
        ShowLIST(HEAD_NODE);
        cout << "Pilihan : ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                cout << endl << endl;
                cout << "Fungsi Insert First" << endl;
                cout << "-----------------------------" << endl;
                cout << "Input NIM: ";
                cin.ignore();
                getline(cin, NIM);
                cout << "Input Nilai UTS: ";
                cin >> Nilai_UTS;
                cout << "Input Nilai UAS: ";
                cin >> Nilai_UAS;
                InsertFirst(&HEAD_NODE, NIM, Nilai_UTS, Nilai_UAS);
                break;
            }
            case 2: {
                cout << endl << endl;
                cout << "Fungsi Insert Last" << endl;
                cout << "-----------------------------" << endl;
                cout << "Input NIM: ";
                cin.ignore();
                getline(cin, NIM);
                cout << "Input Nilai UTS: ";
                cin >> Nilai_UTS;
                cout << "Input Nilai UAS: ";
                cin >> Nilai_UAS;
                InsertLast(&HEAD_NODE, NIM, Nilai_UTS, Nilai_UAS);
                break;
            }
            case 3: {
                cout << endl << endl;
                cout << "Fungsi Delete First" << endl;
                cout << "-----------------------------" << endl;
                DeleteFirst(&HEAD_NODE);
                break;
            }
            case 4: {
                cout << endl << endl;
                cout << "Fungsi Delete Last" << endl;
                cout << "-----------------------------" << endl;
                DeleteLast(&HEAD_NODE);
                break;
            }
            case 5: {
                cout << endl << endl;
                cout << "Program selesai" << endl;
                cout << "-----------------------------" << endl;
                break;
            }
            default: {
                cout << "Pilihan salah.." << endl << endl;
            }
        }

        cout << "Press any key.." << endl << endl;
        getch();

    } while (pilih != 5);

    return 0;
}

Mahasiswa* CREATE_NODE(string NIM, double Nilai_UTS, double Nilai_UAS) {
    Mahasiswa* newNODE = new Mahasiswa();
    newNODE->NIM = NIM;
    newNODE->Nilai_UTS = Nilai_UTS;
    newNODE->Nilai_UAS = Nilai_UAS;
    newNODE->next = NULL;
    return newNODE;
}

void ShowLIST(Mahasiswa* NODE_Penunjuk) {
    if (jml_node == 0) {
    } else {
        while (NODE_Penunjuk != NULL) {
            cout << NODE_Penunjuk->NIM << "              "
                 << NODE_Penunjuk->Nilai_UTS << "          "
                 << NODE_Penunjuk->Nilai_UAS << endl;
            NODE_Penunjuk = NODE_Penunjuk->next;
        }
        cout << "Jumlah Data ada : " << jml_node <<endl;
        cout << "-----------------------------" << endl;
    }
}

void InsertFirst(Mahasiswa** H_NODE, string NIM, double Nilai_UTS, double Nilai_UAS) {
    Mahasiswa* TEMP_NODE = CREATE_NODE(NIM, Nilai_UTS, Nilai_UAS);
    TEMP_NODE->next = *H_NODE;
    *H_NODE = TEMP_NODE;
    jml_node++;
}

void InsertLast(Mahasiswa** H_NODE, string NIM, double Nilai_UTS, double Nilai_UAS) {
    Mahasiswa* TEMP_NODE = CREATE_NODE(NIM, Nilai_UTS, Nilai_UAS);
    if (*H_NODE == NULL) {
        *H_NODE = TEMP_NODE;
    } else {
        Mahasiswa* lastNode = *H_NODE;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = TEMP_NODE;
    }
    jml_node++;
}

void DeleteFirst(Mahasiswa** H_NODE) {
    if (*H_NODE == NULL) {
        cout << "Delete NODE tidak bisa dilakukan karena Linked List kosong" << endl;
    } else {
        Mahasiswa* tempNode = *H_NODE;
        *H_NODE = tempNode->next;
        delete tempNode;
        jml_node--;
    }
}

void DeleteLast(Mahasiswa** H_NODE) {
    Mahasiswa* tempNode = *H_NODE;
    Mahasiswa* prevNode = NULL;
    if (*H_NODE == NULL) {
        cout << "Delete NODE tidak bisa dilakukan karena Linked List kosong" << endl;
    } else if (tempNode->next == NULL) {
        // Hanya satu node
        delete tempNode;
        *H_NODE = NULL;
        jml_node--;
    } else {
        while (tempNode->next != NULL) {
            prevNode = tempNode;
            tempNode = tempNode->next;
        }

        if (prevNode != NULL) {
            prevNode->next = NULL;
        } else {
            *H_NODE = NULL;
        }

        delete tempNode;
        jml_node--;
    }
}
