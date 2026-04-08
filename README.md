# My C++ Raylib Project

This project is a simple application developed using C/C++ and the Raylib library. It demonstrates the use of structures, pointers, and recursion in a graphical environment.

## Project Structure

```
my-cpp-raylib-project
├── src
│   ├── main.c          # Entry point of the application
│   ├── app.h           # Header file for application functions and structures
│   ├── app.c           # Implementation of main application logic
│   └── utils
│       ├── recursion.c  # Implementation of recursive functions
│       └── recursion.h  # Header file for recursive functions
├── include
│   └── app.h           # Public API declarations (duplicate of src/app.h)
├── Makefile            # Build instructions for the project
├── README.md           # Project documentation
└── .gitignore          # Files and directories to ignore by Git
```

## Setup Instructions

1. **Clone the repository:**
   ```bash
   git clone <repository-url>
   cd my-cpp-raylib-project
   ```

2. **Install Raylib:**
   Follow the installation instructions for Raylib based on your operating system. You can find the instructions on the [Raylib GitHub page](https://github.com/raysan5/raylib).

3. **Build the project:**
   Use the provided Makefile to compile the project:
   ```bash
   make
   ```

4. **Run the application:**
   After building, you can run the application with:
   ```bash
   ./my-cpp-raylib-project
   ```

## Usage

This application is a simple Pong game developed using C/C++ and the Raylib library. It demonstrates the use of structures, pointers, and recursion in a graphical environment.

**Gameplay:**
- Player 1 (left): W/S to move paddle.
- Player 2 (right): Up/Down arrows to move paddle.
- Hit the ball with paddles to score.
- First to 5 points wins.

It includes features such as:

- Utilizing structures and pointers to manage application state.
- Implementing recursive functions for various tasks, such as calculating Fibonacci numbers or traversing data structures.

Feel free to explore and modify the code to enhance functionality or add new features!

## Structure de la Présentation Oral

Conformément aux consignes de soutenance :

### 1. Setup
- Environnement de développement : VS Code avec extensions C/C++ et GitHub Copilot.
- Compilateur : GCC ou équivalent pour C.
- Bibliothèque : Installation et utilisation de Raylib.

### 2. Concepts Techniques
- **Structures** : Utilisation de `AppState` et `GameData` pour gérer l'état de l'application.
- **Pointeurs** : Passage de pointeurs aux fonctions pour modifier les données (ex: `InitGame(GameData *data)`).
- **Récursivité** : Fonctions `factorial` et `fibonacci` dans `recursion.c`.
- **Bibliothèques** : Intégration de Raylib pour les graphiques.

### 3. Auto-apprentissage
- Notions apprises : Gestion mémoire avec pointeurs, optimisation récursive, intégration de bibliothèques externes.

### 4. Focus Fonction
- Analyse détaillée de la fonction `fibonacci` : Cas de base, appel récursif, complexité temporelle.

## Collaboration GitHub
- Dépôt public avec code source, headers .h, et README.
- Inviter tous les membres du groupe comme collaborateurs.
- Contributions de chaque membre via push.

## Action LinkedIn
- Publier un post avec vidéo démo, lien GitHub (si public).
- Tags : Membres du groupe, M. Mehdi EL IRAKI, M. Chafik BOULEALAM.

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.