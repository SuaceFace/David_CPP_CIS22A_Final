# David_CPP_CIS22A_Final

This is the final exam we received for CIS22A(intro to CPP). My answer is in main.cpp.

Question 1:
The user inputs a name, id, and phone number, all as strings.
Combine the name and id into a single string, nameid. 
Then, for every digit in the phone number, rotate the nameid to the right if it is even, left if the digit is odd. Rotate it by a number of characters equal to the digit.
- EX: nameid is david123. phone is 4567891234.
- First digit of phone is 4. 4 is even. Rotate nameid to the right by 4 characters.
- Print out the name id.
- Second digit of phone is 5. 5 is odd. Rotate nameid to the left by 5 characters.
- Print out the name id.
- Repeat until all digits in phone have been used.

Accomplish this with a function, rotate_string, which takes the nameid, an integer(the current phone digit), and a boolean(right or left).

After doing this, do the whole process again, but in reverse.(Rotate even numbers to the left, odd numbers to the right). The final result should be the initial nameid.


Question 2:
The user inputs a file input name and file output name(requires address of file in storage).
Open the input file and output file.
If opening fails, print "Failed to open file:" and exit program.
For each line, count how many times each letter of your name appears.
Then, print to console how many times each letter appeared in the input file, and add that number into the output file.
- EX: My name is David. I need to count how the occurrences of D, A, V, and I are in the input file. 
Close both input and output file afterwards.
