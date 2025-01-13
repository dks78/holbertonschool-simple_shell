<h1><p align="center">Ghost Shell - Un shell simple</h1></p></font>

# GSH  
Ghost Shell, également connu sous le nom de "shell", est une interface en ligne de commande simple qui exécute les commandes les plus basiques présentes dans le shell bash.  
*Ghost Shell, also known as the "shell", is a simple command-line interface that executes the most basic commands found in the bash shell.*  


Le shell comporte des processus de sortie , descripteurs de fichiers , ainsi que les appels système.Au démarrage du systéme, trois flux de données sont ouverts:


stdin : stdin est le flux d'entrée standard dans un programme, généralement associé au clavier , Il permet de lire les entrées de l'utilisateur ou d'un fichier (lorsque redirigé).( ce que l'utilisateur , va entrer au clavier )

stdout : stdout est le flux de sortie standard, généralement associé à l'écran (la console). Il permet d'envoyer des données à la sortie standard. ( exemple , si j'entre
al commande ls , ca sera se fichier qui sera utilisé pour entrer affiche la commande ls )

stderr : stderr est le flux d'erreur standard, utilisé pour afficher les messages d'erreur.




Ce shell a été développé comme projet pour l'école Holberton.  
*This shell was developed as a project for Holberton School.*  

`le shell` fonctionne comme bash et d'autres shells basiques.  
*`The shell` works like bash and other basic shells.*  

Le shell peut être compilé à l'aide du compilateur GCC 4.8.5 ou des versions ultérieures.  
*The shell can be compiled using the GCC 4.8.5 compiler or later versions.*  

Il peut être compilé avec la commande suivante :  
*It can be compiled using the following command:*  
`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o shell`.  

---

## Exemple de lancement du shell après compilation :  
*Example of launching the shell after compilation:*  
`./shell`  

**Sortie** : Invite dans le terminal : `$`  
*Output: Prompt in the terminal: `$`*  

---

## Syntaxe  
Le shell fonctionne grâce aux commandes saisies par l'utilisateur.  
*The shell works based on commands entered by the user.*  

Les commandes du shell suivent la syntaxe suivante : `nom_de_commande {arguments}`.  
*Shell commands follow this syntax: `command_name {arguments}`.*  

Le shell exécute une commande après qu'elle est saisie par l'utilisateur, suivie de ses arguments.  
*The shell executes a command after it is entered by the user, followed by its arguments.*  

Exemple :  
*Example:*  
`cat holberton.h`  
Dans cet exemple, la commande saisie est `cat` (utilisée pour afficher un fichier sans l'ouvrir) suivie de l'argument `holberton.h` (le nom du fichier).  
*In this example, the command entered is `cat` (used to display a file without opening it) followed by the argument `holberton.h` (the file name).*  

Pour plus d'informations sur `cat`, vous pouvez utiliser la commande `man`, qui affichera un manuel détaillant la commande ou toute autre commande que vous souhaitez comprendre.  
*For more information on `cat`, you can use the `man` command, which will display a manual detailing the command or any other command you wish to understand.*  

Le manuel contient des informations sur les appels système, les bibliothèques, et d'autres fichiers importants.  
*The manual contains information about system calls, libraries, and other important files.*  

Le shell contient également deux commandes intégrées (builtins) : `exit` et `env`.  
*The shell also contains two built-in commands (builtins): `exit` and `env`.*  

Vous pouvez aussi utiliser la commande `help` pour connaître les commandes intégrées fournies par le shell.  
*You can also use the `help` command to know the built-in commands provided by the shell.*  

La commande `help` fonctionne de manière similaire à `man` en fournissant des informations supplémentaires sur les commandes intégrées.  
*The `help` command works similarly to `man` by providing additional information about the built-in commands.*  

---

### Compilation  
Tous les fichiers peuvent être compilés avec la commande suivante :  
*All files can be compiled with the following command:*  
`$ gcc -Wall -Werror -Wextra -pedantic *.c`  

---

### Liste des commandes utiles  
*List of useful commands:*  
* `cat` - Affiche et concatène des fichiers vers la sortie standard  
    *`cat` - Prints and concatenates files to the standard output.*  
* `cp` - Copie un fichier dans un autre  
    *`cp` - Copies a file into another file.*  
* `grep` - Recherche un fichier selon un modèle spécifique  
    *`grep` - Searches for a file based on a specific pattern.*  
* `less` - Permet de naviguer en avant et en arrière dans les fichiers  
    *`less` - Allows you to navigate backward and forward in files.*  
* `ls` - Liste tous les fichiers et répertoires dans le répertoire de travail courant  
    *`ls` - Lists all files and directories in the current working directory.*  
* `mv` - Déplace un fichier vers un autre fichier  
    *`mv` - Moves one file to another file.*  
* `pwd` - Affiche le répertoire de travail courant  
    *`pwd` - Displays the current working directory.*  

---

### Builtins  
Le shell contient deux commandes intégrées.  
*The shell contains two built-in commands.*  

Voici leur description et leur utilisation :  
*Below is their description and usage:*  

* `env` - La commande `env` permet au shell d'afficher toutes les variables d'environnement avec leurs valeurs.  
    *`env` - The `env` command allows the shell to display all environment variables with their values.*  

* Cela permet d'accéder à ces valeurs via le shell.  
    *This provides access to these values through the shell.*  

* `exit` - Si vous souhaitez quitter le shell, vous pouvez utiliser la commande intégrée `exit`.  
    *`exit` - If you wish to exit the shell, you can use the built-in `exit` command.*  

---

### Sortir des commandes et du shell  
Pour arrêter une commande ou un processus, vous pouvez utiliser `Ctrl + C`.  
*To stop a command or process, you can use `Ctrl + C`.*  

Cette commande interrompt le processus en cours.  
*This command interrupts the ongoing process.*  

Vous pouvez également utiliser `Ctrl + D` pour quitter le shell.  
*You can also use `Ctrl + D` to exit the shell.*  

Lorsque la commande `Ctrl + D` est utilisée, un statut de sortie de `0` est retourné.  
*When the `Ctrl + D` command is used, an exit status of `0` is returned.*  

Avec la commande `exit`, vous pouvez spécifier un statut de sortie ou utiliser le statut par défaut correspondant au dernier processus exécuté.  
*With the `exit` command, you can specify an exit status or use the default status of the last executed process.*  

---

## Fichiers  
*Files:*  
* `README.md` : Ce fichier, contenant des informations sur ce projet  
    *`README.md` : This file, containing information about this project.*  
* `holberton.h` : Fichier d'en-tête contenant tous les prototypes des fonctions utilisées ainsi que les bibliothèques  
    *`holberton.h` : Header file containing all function prototypes used as well as libraries.*  
* `hsh.c` : Fichier principal contenant la plupart des fonctions et leur exécution  
    *`hsh.c` : Main file containing most functions and their execution.*  
* `ghostinshell.png` : Image utilisée dans le fichier README  
    *`ghostinshell.png` : Image used in the README file.*  
* `_getenv.c` : Contient le code pour `_printf`  
    *`_getenv.c` : Contains the code for `_printf`.*  
* `_getline.c` : Fichier pour gérer l'invite et la saisie utilisateur  
    *`_getline.c` : File for managing the prompt and user input.*  
* `which.c` : Fichier contenant les fonctions spécifiques aux spécificateurs de conversion  
    *`which.c` : File containing functions specific to conversion specifiers.*  
* `builtin_execute.c` : Fichier pour exécuter les builtins  
    *`builtin_execute.c` : File for executing the built-ins.*  
* `builtins.c` : Fichier contenant les deux builtins  
    *`builtins.c` : File containing the two built-ins.*  
* `child.c` : Fichier pour créer des processus parent/enfant  
    *`child.c` : File for creating parent/child processes.*  
* `free.c` : Fichier contenant les fonctions de libération de mémoire  
    *`free.c` : File containing memory-freeing functions.*  
* `prompt.c` : Fichier contenant la ligne d'invite `$`  
    *`prompt.c` : File containing the `$` prompt line.*  
* `tokenizer.c` : Fichier contenant une fonction pour tokeniser un tableau de chaînes de caractères  
    *`tokenizer.c` : File containing a function to tokenize an array of strings.*  
* `utility_functions.c` : Fichier contenant des fonctions utilitaires  
    *`utility_functions.c` : File containing utility functions.*  
### Commentaires  
*Comments:*  

---

### Auteurs  
*Auteurs:* 

* Aurélien Mestry - https://github.com/dks78
