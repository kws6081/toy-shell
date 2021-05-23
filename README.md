# toy-shell
Computer Architecture and Real-Time Operating System
Project#1

## Development Environment
Ubuntu 18.04

## How to Run aShell
1. Download
```
git clone https://github.com/kws6081/toy-shell
cd /toy-shell
```

2. Complie C codes
```
gcc -o ashell shell.c && gcc -o info info.c && gcc -o red red.c && gcc -o undocolor undocolor.c
```

3. Run ashell
```
./ashell
```

4. Run commands
```
Every commands in /bin.
info
red
undocolor
clear
exit
```

## Features and Commands
1. There are 3 kinds of commands in aShell.  
(1)Commands from /bin,  
(2)Commands made by compiling info.c, red.c, undocolor.c,  
(3)Commands defined in shell.c.  

2. Every commands in /bin which require 3 arguments or less are available.  
```
mkdir a  
ls  
ls -al  
cp shell.c a  
cat info.c  
...
```

3. info : Shows information about aShell.  
```
username@hostname:~/toy-shell $ : info  
```

4. red & undocolor: Make letters red, Make letters black again.  
```
username@hostname:~/toy-shell $ : red  
username@hostname:~/toy-shell $ : undocolor  
```

5. clear : Clears Shell.  
```
username@hostname:~/toy-shell $ : clear  
```

6. exit : Terminate Shell.  
```
username@hostname:~/toy-shell $ : exit  
```

7. aShell reads current directory and changes "/home/username" into "~", and root directory into "/" as it does in Ubuntu.  
