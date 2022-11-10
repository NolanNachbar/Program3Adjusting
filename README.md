Program #2

Name: Nolan Nachbar

COSC 2030

Section #01

Competing: 

NO

Best run time: 

7.3 seconds on PI

compile line: 

g++ -o prog2.cpp Prog2.cpp

to Run after compiling:
./prog2.cpp

Anything that doesn't work:
N/A


---
grading 93/100<BR>
* github, compiles, and  run (10 points ) yes
* cover page correct (2 points) yes
* readme updated and correct (2 points) yes
* data structure is binary search tree (25 points) no
  * issues in the data structure like the destructor no 
  * no constructor nor destructor.  dangerous assumtion of nullptr without a constructor -5
* cleaword method (12 points) yes
* read dictionary (5 points) yes
  * calls clean word
* reads book (5 points) yes
  * calls clean word
* skipped correct (5 points) yes
* spelling checking code correct (10 points)  yes
  * so you created a class for the vector that actually the vector does without needing an extra class.  odd. you could just delcare it string.
* compare counts are correct (10 points) no
  * the find you have miscounted.  the first else if, yes that one compare, so tempcomp++ works.  But the section else if and final else, there have been 2 compares, not one.  -2
* format/output correct (10 points) yes
  * spelled and misspelled
  * misspelled file? yes
* timing code and run time (4 points) yes
* competeing, Extra credit: no

and Notes:<BR>
* compiles and runs.  numbers look good.  compares are for some optimization or miscounted.
