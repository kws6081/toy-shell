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

2. Every commands in /bin which require less than 4 arguments are available.  
((1)Commands from /bin)  
'''
mkdir a  
ls  
ls -al  
cp shell.c a  
cat info.c  
...
'''

3. info : Shows information about aShell.  
((2)Commands made by compiling info.c, red.c, undocolor.c)  
'''
username@hostname:~/toy-shell $ : info  
'''

4. red & undocolor: Make letters red, Make letters black again.  
((2)Commands made by compiling info.c, red.c, undocolor.c)  
'''
username@hostname:~/toy-shell $ : red  
username@hostname:~/toy-shell $ : undocolor  
'''

5. clear : Clears Shell.  
((3)Commands defined in shell.c.)  
'''
username@hostname:~/toy-shell $ : clear  
'''

6. exit : Terminate Shell.  
((3)Commands defined in shell.c.)  
'''
username@hostname:~/toy-shell $ : exit  
'''

7. aShell reads current directory and changes "/home/username" into "~", and root directory into "/" as it does in Ubuntu.  
