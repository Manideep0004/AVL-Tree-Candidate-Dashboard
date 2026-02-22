#include <bits/stdc++.h>
using namespace std;

struct Candidate {
    string name;
    string skill;
    int score;
    Candidate(string n = "", string s = "", int sc = 0) : name(n), skill(s), score(sc) {}
};

struct AVLNode {
    Candidate candidate;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(Candidate c) : candidate(c), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) { return node ? node->height : 0; }

    int getBalance(AVLNode* node) { return node ? getHeight(node->left) - getHeight(node->right) : 0; }

    void updateHeight(AVLNode* node) {
        if (node) node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    AVLNode* insertHelper(AVLNode* node, const Candidate& candidate) {
        if (!node) return new AVLNode(candidate);

        if (candidate.score < node->candidate.score)
            node->left = insertHelper(node->left, candidate);
        else if (candidate.score > node->candidate.score)
            node->right = insertHelper(node->right, candidate);
        else if (candidate.name < node->candidate.name)
            node->left = insertHelper(node->left, candidate);
        else
            node->right = insertHelper(node->right, candidate);

        updateHeight(node);
        int balance = getBalance(node);

        // LL
        if (balance > 1 && node->left
            && (candidate.score < node->left->candidate.score ||
                (candidate.score == node->left->candidate.score && candidate.name < node->left->candidate.name)))
            return rotateRight(node);

        // RR
        if (balance < -1 && node->right
            && (candidate.score > node->right->candidate.score ||
                (candidate.score == node->right->candidate.score && candidate.name > node->right->candidate.name)))
            return rotateLeft(node);

        // LR
        if (balance > 1 && node->left
            && (candidate.score > node->left->candidate.score ||
                (candidate.score == node->left->candidate.score && candidate.name > node->left->candidate.name))) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // RL
        if (balance < -1 && node->right
            && (candidate.score < node->right->candidate.score ||
                (candidate.score == node->right->candidate.score && candidate.name < node->right->candidate.name))) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    void inorderHelper(AVLNode* node, vector<Candidate>& candidates) {
        if (node) {
            inorderHelper(node->left, candidates);
            candidates.push_back(node->candidate);
            inorderHelper(node->right, candidates);
        }
    }

    void reverseInorderHelper(AVLNode* node, vector<Candidate>& candidates) {
        if (node) {
            reverseInorderHelper(node->right, candidates);
            candidates.push_back(node->candidate);
            reverseInorderHelper(node->left, candidates);
        }
    }

    void searchBySkillHelper(AVLNode* node, const string& skill, vector<Candidate>& results) {
        if (node) {
            if (node->candidate.skill == skill)
                results.push_back(node->candidate);
            searchBySkillHelper(node->left, skill, results);
            searchBySkillHelper(node->right, skill, results);
        }
    }

    void cleanup(AVLNode* node) {
        if (node) {
            cleanup(node->left);
            cleanup(node->right);
            delete node;
        }
    }

public:
    AVLTree() : root(nullptr) {}
    ~AVLTree() { cleanup(root); }

    void insert(const Candidate& candidate) { root = insertHelper(root, candidate); }

    vector<Candidate> getInorder() {
        vector<Candidate> v; inorderHelper(root, v); return v;
    }

    vector<Candidate> getReverseInorder() {
        vector<Candidate> v; reverseInorderHelper(root, v); return v;
    }

    vector<Candidate> searchBySkill(const string& skill) {
        vector<Candidate> results;
        searchBySkillHelper(root, skill, results);
        sort(results.begin(), results.end(), [](const Candidate& a, const Candidate& b) {
            if (a.score != b.score) return a.score > b.score;
            return a.name < b.name;
        });
        return results;
    }

    bool isEmpty() { return root == nullptr; }
};

void displayMenu() {
    cout << "\n=== Skill-Based Candidate Shortlisting System ===\n";
    cout << "1. Add New Candidate\n2. Display All Candidates (Descending Score Order)\n";
    cout << "3. Search Candidates by Skill\n4. Display All Candidates (Ascending Score Order)\n5. Exit\n";
    cout << "Enter your choice: ";
}

void displayCandidates(const vector<Candidate>& candidates, const string& title) {
    cout << "\n" << title << "\n" << string(title.length(), '=') << "\n";
    if (candidates.empty()) { cout << "No candidates found.\n"; return; }
    cout << left << setw(25) << "Name" << setw(20) << "Skill" << setw(6) << "Score" << "\n";
    cout << string(55, '-') << "\n";
    for (const auto& c : candidates)
        cout << left << setw(25) << c.name << setw(20) << c.skill << setw(6) << c.score << "\n";
    cout << "\nTotal candidates: " << candidates.size() << "\n";
}

Candidate getCandidateInput() {
    string name, skill;
    int score;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover
    cout << "\nEnter candidate details:\nName: ";
    getline(cin, name);
    cout << "Skill: ";
    getline(cin, skill);
    cout << "Score (0-100): ";
    while (!(cin >> score) || score < 0 || score > 100) {
        cout << "Invalid! Enter integer 0-100: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return Candidate(name, skill, score);
}

int main() {
    AVLTree candidateTree;
    int choice = 0;

    // sample data
    candidateTree.insert(Candidate("Ravi", "Python", 85));
    candidateTree.insert(Candidate("Amit", "Java", 92));
    candidateTree.insert(Candidate("Priya", "C++", 78));
    candidateTree.insert(Candidate("Anjali", "Python", 88));
    candidateTree.insert(Candidate("Rahul", "JavaScript", 90));
    candidateTree.insert(Candidate("Sonia", "Java", 82));
    candidateTree.insert(Candidate("Pooja", "C++", 95));
    candidateTree.insert(Candidate("Dhruv", "Python", 88));

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
            continue;
        }

        if (choice == 1) {
            Candidate c = getCandidateInput();
            candidateTree.insert(c);
            cout << "\nCandidate added successfully!\n";
        } else if (choice == 2) {
            displayCandidates(candidateTree.getReverseInorder(), "All Candidates (Highest → Lowest)");
        } else if (choice == 3) {
            string skill;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter skill to search: ";
            getline(cin, skill);
            displayCandidates(candidateTree.searchBySkill(skill), "Search Results for: " + skill);
        } else if (choice == 4) {
            displayCandidates(candidateTree.getInorder(), "All Candidates (Lowest → Highest)");
        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Enter a number between 1 and 5.\n";
        }
    }

    return 0;
}
