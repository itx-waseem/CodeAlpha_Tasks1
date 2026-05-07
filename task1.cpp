#include <iostream>
#include <vector>
using namespace std;
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

struct Flashcard {
    string question;
    string answer;
};

vector<Flashcard> cards;
int currentIndex = 0;
void showCard() {
    if (cards.empty()) {
        cout << RED << "No flashcards available.\n" << RESET;
        return;
    }
    
    cout << CYAN << "\nCard " << currentIndex + 1 << "/" << cards.size() << RESET << endl;
    cout << BOLD << BLUE << "Q: " << cards[currentIndex].question << RESET << endl;
    cout << YELLOW << "Press 's' to show answer: " << RESET;
    char ch;
    cin >> ch;

    if (ch == 's' || ch == 'S') {
        cout << GREEN << "A: " << cards[currentIndex].answer << RESET << endl;
    }
}

void addCard() {
    Flashcard f;
    cin.ignore();

    cout << GREEN << "Enter question: " << RESET;
    getline(cin, f.question);

    cout << GREEN << "Enter answer: " << RESET;
    getline(cin, f.answer);

    cards.push_back(f);
    cout << GREEN << "Flashcard added!\n" << RESET;
}

// Edit
void editCard() {
    if (cards.empty()) {
        cout << RED << "No cards to edit.\n" << RESET;
        return;
    }

    cin.ignore();
    cout << YELLOW << "Editing Card " << currentIndex + 1 << RESET << endl;

    cout << "New question: ";
    getline(cin, cards[currentIndex].question);

    cout << "New answer: ";
    getline(cin, cards[currentIndex].answer);

    cout << GREEN << "Flashcard updated!\n" << RESET;
}

void deleteCard() {
    if (cards.empty()) {
        cout << RED << "No cards to delete.\n" << RESET;
        return;
    }

    cards.erase(cards.begin() + currentIndex);

    if (currentIndex >= cards.size() && currentIndex > 0) {
        currentIndex--;
    }

    cout << RED << "Flashcard deleted!\n" << RESET;
}

void nextCard() {
    if (currentIndex < cards.size() - 1) {
        currentIndex++;
    } else {
        cout << RED << "Already at last card.\n" << RESET;
    }
}

void prevCard() {
    if (currentIndex > 0) {
        currentIndex--;
    } else {
        cout << RED << "Already at first card.\n" << RESET;
    }
}

void menu() {
    cout << BOLD << CYAN << "\n===== Flashcard App =====\n" << RESET;
    cout << BLUE   << "1. Show Card\n";
    cout << CYAN   << "2. Next Card\n";
    cout << CYAN   << "3. Previous Card\n";
    cout << GREEN  << "4. Add Card\n";
    cout << YELLOW << "5. Edit Card\n";
    cout << RED    << "6. Delete Card\n";
    cout << BOLD   << "7. Exit\n" << RESET;
    cout << "Choose: ";
}

int main() {
    int choice;

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: showCard(); break;
            case 2: nextCard(); break;
            case 3: prevCard(); break;
            case 4: addCard(); break;
            case 5: editCard(); break;
            case 6: deleteCard(); break;
            case 7: cout << GREEN << "Goodbye!\n" << RESET; return 0;
            default: cout << RED << "Invalid choice.\n" << RESET;
        }
    }
}
