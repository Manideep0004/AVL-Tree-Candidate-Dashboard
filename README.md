# 🌳 AVL Tree Candidate Dashboard

A comprehensive skill-based candidate shortlisting system built with **AVL Trees** in C++ and an interactive visualization dashboard in HTML/JavaScript.

## 📋 Overview

This project demonstrates the implementation and visualization of **self-balancing Binary Search Trees (AVL Trees)** for efficiently managing and searching candidate data based on scores and skills. The system combines production-ready C++ code with an interactive web-based dashboard for learning and demonstration.

## ✨ Features

### C++ Implementation (`DSA_Project/main.cpp`)
- ✅ **AVL Tree Data Structure** - Self-balancing binary search tree with automatic rotations
- ✅ **Add Candidates** - Insert new candidates with name, skill, and score
- ✅ **Search Operations** - Search by skill with score-based sorting
- ✅ **Tree Traversal** - Inorder and reverse inorder traversals
- ✅ **Auto-Balancing** - Maintains O(log n) time complexity with LL, RR, LR, and RL rotations
- ✅ **Input Validation** - Score validation (0-100), duplicate prevention
- ✅ **Interactive Menu** - Command-line interface for easy interaction

### Web Dashboard (`dashboard.html`)
- 🎨 **Real-time Tree Visualization** - D3.js powered interactive tree display
- ➕ **Add Candidates** - Web form to add candidates dynamically
- 📊 **Tree Statistics** - Shows tree height, total nodes, and balance factor
- 📋 **Candidate List** - Displays candidates sorted by score (descending)
- 🎯 **Sample Data** - Pre-loaded with 8 sample candidates for exploration
- 🎭 **Beautiful UI** - Modern gradient design with smooth animations
- 📱 **Responsive Design** - Works on desktop and mobile devices

## 🏗️ Project Structure

```
CPP_Codespace/
├── dashboard.html              # Interactive web dashboard
├── README.md                   # This file
├── main                        # Compiled C++ executable
└── DSA_Project/
    └── main.cpp               # AVL Tree C++ implementation
```

## 🚀 Getting Started

### Prerequisites
- **C++ Compiler**: g++ or clang
- **Python 3**: For running HTTP server (optional, for dashboard)
- **Modern Web Browser**: For dashboard visualization
- **Git**: For version control

### Installation

```bash
# Clone the repository
git clone https://github.com/Mani0004/CPP_Codespace.git
cd CPP_Codespace
```

## 📖 Usage

### Option 1: Run C++ Program (CLI)

```bash
# Compile the C++ code
g++ DSA_Project/main.cpp -o main

# Run the program
./main
```

**Menu Options:**
1. Add new candidate
2. Display all candidates (highest → lowest score)
3. Search by skill
4. Display all candidates (lowest → highest score)
5. Exit

### Option 2: Use Web Dashboard (Interactive)

```bash
# Start HTTP server
python3 -m http.server 8000

# Or use Node.js if installed
npx http-server
```

**Then open in browser:**
```
http://localhost:8000/dashboard.html
```

## 💡 How AVL Trees Work

### Key Concepts

| Aspect | Benefit |
|--------|---------|
| **Height Balance** | Left and right subtrees differ by at most 1 |
| **Time Complexity** | O(log n) for search, insert, delete (guaranteed) |
| **Rotations** | LL, RR, LR, RL cases maintain balance |
| **Use Cases** | Databases, file systems, priority queues |

### Rotations

```
Left Rotation     Right Rotation     Left-Right       Right-Left
    Z                 X                A                 C
   / \              / \              / \               / \
  X   T4    →      T1   Z    →      B   C     →       A   D
 / \                   / \           / \               / \
T1  Y                 Y   T4        T1  B             C   T4
   / \               / \               / \           / \
  T2 T3             T2 T3             T2 T3         T1 T2
```

## 📊 Example Walkthrough

### Adding Candidates

1. **Initial Tree** (with sample data):
   ```
           85
          /  \
        78    92
       / \    / \
      76 81  88 95
             /
           89
   ```

2. **Add "John Doe" with score 80**:
   - Tree detects imbalance
   - Performs rotation to maintain height balance
   - Final height ≤ log₂(n)

3. **Result**: Tree remains balanced, search operations stay efficient

## 🎓 Data Structures & Algorithms

### Candidate Structure
```cpp
struct Candidate {
    string name;      // Candidate name
    string skill;     // Primary skill
    int score;        // Score (0-100)
};
```

### AVL Node Structure
```cpp
struct AVLNode {
    Candidate candidate;
    AVLNode* left;
    AVLNode* right;
    int height;        // Maintains balance
};
```

### Key Operations

| Operation | Time | Space |
|-----------|------|-------|
| Insert | O(log n) | O(1) |
| Search | O(log n) | O(1) |
| Delete | O(log n) | O(1) |
| Traversal | O(n) | O(log n) |

## 🔧 Technical Stack

### C++ Implementation
- **Language**: C++11
- **Standard Library**: `bits/stdc++.h`
- **Paradigm**: Object-Oriented Programming
- **Compilation**: G++ with standard flags

### Web Dashboard
- **Frontend**: HTML5 + CSS3
- **Visualization**: D3.js v7
- **JavaScript**: ES6+
- **Design**: Responsive CSS Grid/Flexbox

## 🤝 How to Contribute

```bash
# Fork the repository
# Create a feature branch
git checkout -b feature/your-feature

# Make your changes
git add .
git commit -m "Add your feature"

# Push to GitHub
git push origin feature/your-feature

# Create a Pull Request
```

## 📚 Learning Resources

- **AVL Trees**: https://en.wikipedia.org/wiki/AVL_tree
- **D3.js Documentation**: https://d3js.org/
- **C++ STL**: https://cplusplus.com/reference/

## 🎯 Use Cases

✅ **Educational**: Learn AVL tree concepts with visualization
✅ **Interview Preparation**: Understand balanced BST operations
✅ **Production**: High-performance candidate management system
✅ **Research**: Benchmark AVL implementations
✅ **Demonstrations**: Show tree balancing in real-time

## 📝 Sample Data

The system comes with 8 pre-loaded candidates:

| Name | Skill | Score |
|------|-------|-------|
| Alice Johnson | Python | 85 |
| Bob Smith | JavaScript | 78 |
| Carol White | Java | 92 |
| David Brown | C++ | 88 |
| Eve Davis | Python | 95 |
| Frank Miller | JavaScript | 81 |
| Grace Lee | Java | 89 |
| Henry Wilson | C++ | 76 |

## 📧 Contact

**Author**: Mani0004
**GitHub**: https://github.com/Mani0004
**Repository**: https://github.com/Mani0004/CPP_Codespace

## 📄 License

This project is open source and available under the MIT License.

## 🙏 Acknowledgments

- AVL Tree concept by Adelson-Velsky and Landis (1962)
- D3.js community for visualization tools
- Contributors and testers

---

**Happy Learning! 🚀**

*Star the repository if you found it helpful!*