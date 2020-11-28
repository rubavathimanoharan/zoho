# FLIGHT TICKET BOOOKING SYSTEM  <br /><br /><br />

## Why Doubly Circular Linked list?<br />
Due to the fact that a circular doubly linked list contains three parts in its structure(i.e. Data,next pointer,previous pointer).<br />
Consecutive elements are linked or connected by previous and next pointer and the last node points to first node by next pointer and also the first node points to last node by previous pointer.<br />
However, a circular doubly linked list provides easy manipulation of the pointers and the searching becomes twice as efficient.<br />
if our head pointer points to the seat number ‘A1’ & user want to perform some operation with seat number ‘J1’ then it will be very
much time consuming task ,as we need to traverse whole linked list from A1 to J7.<br />
When we use Doubly circular Linked List all seats are connected in a ring fashion so we can
directly move from seat A1 to J7 using previous pointer as in previous pointer of head node address of seat J7 is stored.<br /><br />

## Why dynamic memory allocation?<br />
We do not know how much amount of memory would be needed for the program beforehand.<br />
When we want data structures without any upper limit of memory space as well as we should use the memory efficiently,here comes dynamic memory allocation.<br />
Inorder to dynamically allocate memory in runtime ie. there can be any number of seats in any number of rows, we use dynamic memory allocation.<br />
Operations in dynamically created lists can be done very easily just by the manipulation of addresses.<br />
Memory usage can grow and shrink according to the requirement and hence **there is no wastage of memory**.<br />


## FUNCTIONS USED:<br />

### 1.CREATE:<br />
Create a new node for every seat and connect them using doubly linked list.<br />
Generate a unique pin using the formula ,k=(k*k)/10+100-k/2.<br />
Initially set all the seat's status as available.<br />
if,the head node is NULL then set the newnode as the headnode ,else set the newnode as current node and connect the current node with new node and head node.<br />
Follow the above steps for every nodes till the end fo the creation of nodes.<br /><br />

### 2.MAIN:<br />
Read the inputs from the text file given .<br />
Ask the user to select which process to do either to book the seats or cancel the seats or exit the portal.<br />
If the user selects the booking option then call the book_seat function and dsiplay the results.<br />
If the user selects the cancel option then call the cancel function and display the results.<br />
If the user wants to exit the portal then Exit the portal.<br /><br />

### 3.BOOK SEAT:<br />
Get the no.of tickets the user wants to buy and the Seat number Row Name from the user.<br />
If the already booked seat is choosen by the user then display the message that the seat is  already booked.<br />
Calculate the cost of the tickets booked according to the place and class where the tickets are booked.<br />
If the Window seat or asile seat is booked then add extra 100.<br />
Ask the User whether they want meal during travel if yes then add extra 200 to their bill amount .<br />
Finally ask the user whether they want to book other seat or to check the seat status or exit the booking portal and procced accordingly.<br />
If the user wants to book the seat got back to the booking portal again.<br />
IF the user wants to check the status of the seats then display the call the display function to display the status.<br />
IF the user wants to exit the booking portal then go back to the main portal.  <br /><br />


### 4.DISPLAY:<br />
As we get the input from the user window ,asile and middle seats are allocated for both business and economy class.<br />
<pre>For example     WA2 =>    W-Window seat<br />
                           A- Row 1<br />
                           1-Column 1 <br />
                 AB4  =>    A- Asile seat<br />
                            B-Row 2<br />
                            4- column 4<br /></pre>
If the seat is available then display the status as 'a' (i.e. Available)  else display the status as 'b' (i.e.Booked).<br />
Finally call the display1 function.<br /><br />


### 5.DISPLAY1:<br />
Confirmation message for the seats booked and Unique ID for the every booked seat is displayed.<br /><br />



### 6.CANCEL:<br />
Ask the user to enter the seat number and row name the user want to cancel and enter the unique pin already given to the user during the time of registration.<br />
Ask the user once again for the confirmation.<br />
If the row name seat number and Pin  matches the change the status of the seat as 'a'(i.e.available) from 'b'(i.e.booked).<br />
Finally ask the user whether they want to check the seat status or to cancel more tickets or exit the cancellation portal and do the function accordingly.<br /><br />

### 7.COST:<br />
If the class of the  seat booked is Business then calculate the cost as number of tickets * cost of the ticket .<br />
<pre>                       For business class Rs.1500 per seat and exrtra 100 for Window and asile seats.<br />
                        For economy class Rs.1000 per seat and exrtra 100 for Window and asile seats.<br /></pre>
If the user wants meal then add extra 200 with the bill amount.<br />
For example:If  Class=Business , WC4  and no,of.tickets=1<br />
Since the class is business  and seat position is near window , 1500 * no.of.tickets(i.e.1) + (100 extra for window seat)+ (200 for meal) =>1500 * 1 +100  + 200<br />


