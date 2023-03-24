# About Philosophers
This project is about the basics of threading a process, how to create threads and discover mutexes
(find more information in <a href = "https://github.com/svkhacha/Philosophers/files/9814055/en.subject.pdf" target = "_blank">**subject**</a>).

## How to run the program
***./philo*** *[number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]* <br> <br>
**Some cases you need to check    (<a href ="https://github.com/svkhacha/Philosophers/files/9814138/LazyPhilosophersTester.zip" target = "_blank">Tester 📥</a>)**<br>

***./philo 1 800 200 200*** - Philosopher should not eat and should die. <br>
***./philo 5 800 200 200*** - No Philosopher should die. <br>
***./philo 5 800 200 200 7*** - No Philosopher should die and the simulation should stop when every philosopher has eaten at least 7 times. <br>
***./philo 4 410 200 200*** - No Philosopher should die. <br>
***./philo 4 310 200 100*** - One Philosopher should die. <br>

## Useful resources
• <a href = "https://prezi.com/view/fCnFsuYuhrXwcWz3cZaV/" target= "_blank">My presentation about **"Threads and Processes"** </a>

• https://linuxhint.com/the-usleep-3-function-in-c/

• https://linuxhint.com/gettimeofday_c_language/

• https://www.geeksforgeeks.org/thread-functions-in-c-c/

• https://www.geeksforgeeks.org/multithreading-c-2/

• https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/

• https://www.youtube.com/watch?v=NbwbQQB7xNQ

• <a href = "https://code-vault.net/course/6q6s9eerd0:1609007479575" target = "_blank">UNIX Threads in C </a>

## How it looks like
(example in ***"./philo 4 310 200 100"*** case) <br> <br>
![Screenshot from 2022-10-18 23-13-07](https://user-images.githubusercontent.com/115194519/196523299-fdeb590c-4a47-4641-901b-1f3b005401ba.png)


