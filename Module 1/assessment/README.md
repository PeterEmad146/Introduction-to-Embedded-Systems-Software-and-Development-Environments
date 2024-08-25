# Module 2 Assessment

## Guidelines

**Implementation File Guidelines - stats.c**

You are to write a couple of functions that can analyze an array of unsigned char data items and report analytics on the maximum, minimum, mean, and median of the data set. In addition, you will need to reorder this data set from large to small. All statistics should be rounded down to the nearest integer. After analysis and sorting is done, you will need to print that data to the screen in nicely formatted presentation. You will need to submit a version controlled repository of these 3 files. 

1) <code style="color:green">stats.c</code> --> Implementation file for your C-programming code.
2) <code style="color:green">stats.h</code> --> Header file for you C-Programming code
3) <code style="color:green">README.md</code> --> Inculdes information on the author and the project.

The assessment files will be available by using our course1 repository hosted on github. You can git clone the assessments repo from github:

> cd ~ <br>
> git clone https://github.com/afsodick/ese-coursera-course1.git <br>

The folder contains:

The **stats.c** and **stats.h** files have some premade function comment format for you to enter data into. You will need to include your name as the author, the date and a small description of the file at the top. If you open **stats.c** you will see you have been given part of a **main()** function. Main has defined an array of 40 characters for testing. At the top of **README.md**, add your name and description of the repository and project.

You will need to write eight functions in the **stats.c** implementation file.

1) <code style="color:green">main()</code> --> The main entry point for your program.
2) <code style="color:green">print_statistics()</code> --> A function that prints the statistics of an array including minimum, maximum, mean, and median.
3) <code style="color:green">print_array()</code> --> Given an array of data and a length, prints the array to the screen.
4) <code style="color:green">find_median()</code> --> Given an array of data and a length, returns the median value.
5) <code style="color:green">find_mean()</code> --> Given an array of data and a length, returns the mean.
6) <code style="color:green">find_maximum()</code> --> Given an array of data and a length, returns the maximum.
7) <code style="color:green">find_minimum()</code> --> Given an array of data and a length, returns the minimum.
8) <code style="color:green">sort_array()</code> --> given an array of data and a length, sorts the array from the largest to smallest. (The zeroth element hsould be the largest value, and the last element (n-1) should be the smallest value)

Top print data to the screen, you can use the **printf** function provided by the standard IO library (**stdio.h**). Each printed value should be nicely formatted with an indicator of the variable or index for each statistic value printed.

Most of the functions in the **stats.c** file require 2 input parameters and one return value:
- **Input**: A unsigned char pointer to an n-element data array
- **Input**: An unsigned integer as the size of the array
- **Output**: An unsigned char result from the function

**Header file Guildelines - stats.h**

The **stats.h** header file needs to include declarations and documentation for the functions from hte **stats.c** file. You will add function declarations for all required functions except main. With each declaration you need to provide comments with a description of the function, the inputs, and return value. An example is provided below for a function **swap32()** that does a byte swap of a 32-bit data item.

> /** <br>
> \* &emsp; @brief Reverses the byte order of an unsigned 32-bit integer <br>
> \* &emsp; <br>
> \* &emsp; This funciton takes as an input a 32-bit integer. This will <br>
> \* &emsp; reverse the byte order of the full word. Instead of changing the <br>
> \* &emsp; parameter passed it, it will returned a reversed unsigned 32-bit <br>
> \* &emsp; integer. <br>
> \* &emsp; <br>
> \* &emsp; @param word the 32-bit word to be reversed <br>
> \* &emsp; @return The reversed 32-bit value word <br>
> \*/ <br>
> unsigned int swap32 (unsigned int, int word); <br>

**Compilation Guidelines**

To compile and run this code you can run the following commands:

> \$ gcc -o stats.out stats.c <br>
> ./stats.out <br>

## Command Line and Version Control Helper Commands

To get the home dir and create the file you will run the following commands, but replace Fosdick_coursera with your repository name:

> \$ cd ~ <br>
> \$ mkdir Fosdick_Coursera <br>
> \$ cd Fosdick_Coursera <br>
> \$ git init <br>

Once you have an initialized repository you will need to set your committer information. Run hte following commands with your own name and email instead. 

> \$ git config --global user.email "you@example.com" <br>
> \$ git config --global user.name "Your Name" <br>

If you want to create your own README.md file with the touch command or the vim directly (one or the other)

> \$ touch README.md

> \$ vim README.md

Add your description (and copyright as applicable) and then save the file. Move the files provided in hte zip to this directory. NOw you will need to commit this as your initial repository commit to the master branch.

> \$ git add README.md stats.h stats.c <br>
> \$ git commit -m "Creating Initial Coursera Repository"<br>

For the second commit you will start your development by making a development branch with the git branch command. Call this **dev_c1m1**. Checkout out this branch after you created it.

> \$ git branch dev_c1m1 <br>
> \$ git checkout dev_c1m1 <br>

For this second commit you are to only add the files with all of the functions "stubbed" and the associated function and file documentation. Meaning add all function prototypes and function documentation in the header files. All function definitions but with an empty function body in the implementation file.

> \$ git status <br>
> \$ git add stats.h stats.c
> \$ git commit -m "Adding code outline and documentation for C1M1 Assessment" <br>
> \$ git checkout master <br>
> \$ git merge dev_c1m1

For the third (and subsequent commits) you are to begin to code the functions you need to deliver from the requirements of each file. When you are satisfied with your changes, repeat the process committing from the second. If you want to save your repository on a repository store site like github or bitbucket, you need to create an account on those sites and set up an empty repository. Then run the following code to push your developed commits...

> \$ cd /path/to/your/repo <br>
> \$ git remote add origin https://bitbucket.org/ACCOUNT/REPONAME.git <br>
> \$ git push -u origin master

<div align=center>
&copy; University of Colorado Boulder
</div>