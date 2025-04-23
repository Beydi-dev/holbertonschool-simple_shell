# 📌 Projet `simple_shell`

Nous sommes heureux aujourd'hui de vous présenter notre second projet collaboratif en langage C !

## 📖 Introduction  
Ce projet implémente une version simplifiée d’un shell Unix.  
L'objectif est de comprendre en profondeur le fonctionnement d’un shell : lecture des lignes de commande, exécution de processus via `fork`/`execve`, gestion de la mémoire et interprétation des commandes.

---

## 📂 Structure du Projet  
Le projet est organisé en plusieurs fichiers :  

| **Fichier**           | **Description** |
|------------------------|------------------------------------------------|
| `main.c`              | Contient la boucle principale du shell. |
| `main.h`              | Contient les prototypes de fonctions et les `#include` nécessaires. |
| `read_line.c`         | Gère la lecture de la ligne de commande. |
| `tokenize_line.c`     | Découpe la ligne de commande en tokens (commandes/arguments). |
| `execute_command.c`   | Exécute les commandes en utilisant `execve`. |
| `handle_exit.c`       | Gère la commande interne `exit`. |
| `free_argv.c`         | Libère la mémoire allouée au tableau d’arguments. |

---

## ⚙️ Fonctionnalités  
Notre `simple_shell` prend en charge plusieurs fonctionnalités essentielles :

- ✅ Affichage du prompt `$` (si le shell est interactif).  
- ✅ Lecture d'une ligne depuis l'entrée standard.  
- ✅ Découpage de la ligne en arguments avec `strtok`.  
- ✅ Exécution de commandes via `fork` + `execve`.  
- ✅ Commande interne `exit` avec ou sans code de retour.  
- ✅ Commande interne `env` pour afficher les variables d’environnement.  
- ✅ Affichage d’un message d’erreur si la commande est introuvable.  

---

## 🚀 Compilation et Restrictions  
Le projet doit être compilé avec la commande suivante :  
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
./simple_shell
⚠️ Restrictions
✅ Éditeurs autorisés : vi, vim, emacs

✅ Compilation sous : Ubuntu 20.04 LTS

✅ Fichiers compilés avec les options : -Wall -Werror -Wextra -pedantic -std=gnu89

✅ Tous les fichiers doivent se terminer par une nouvelle ligne

✅ Un fichier README.md est obligatoire à la racine du projet

✅ Le code doit respecter la norme Betty (betty-style.pl, betty-doc.pl)

✅ Le shell ne doit contenir aucune fuite mémoire

✅ Maximum 5 fonctions par fichier

✅ Tous les fichiers .h doivent être protégés par des include guards

✅ Utiliser les appels système uniquement lorsque nécessaire
```
🛠 **Technologies utilisées** :  
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)  
![GCC](https://img.shields.io/badge/GCC-4A4A4A?style=for-the-badge&logo=gnu&logoColor=white)  
![Git](https://img.shields.io/badge/GIT-F05032?style=for-the-badge&logo=git&logoColor=white)  
![Visual Studio Code](https://img.shields.io/badge/VS_Code-007ACC?style=for-the-badge&logo=visual-studio-code&logoColor=white)  
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)  

## 🤝 Collaborateurs  

| Nom           | GitHub                 | Rôle |
|--------------|-----------------------|------|
| **Beydi Coulibaly** | [@beydi-dev](https://github.com/Beydi-dev) | étudiant chez Holberton|
| **Ilmi Veliu**  | [@IlmiVeliu](https://github.com/ilmi-veliu)| étudiant chez Holberton|

💡 **Contributions** :  
✅ Développement de `simple shell`  
✅ Gestion des spécifieurs de format  
✅ Respect des normes de codage **Betty**  
✅ Collaboration sur la documentation et le débogage 
