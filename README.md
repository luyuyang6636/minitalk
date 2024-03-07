# MINITALK
### A communication program

In this program, I wrote code for 2 programs - **server** and **client**.

The server must be started first. After launch it will display its PID like this:

![image](https://github.com/luyuyang6636/minitalk/assets/78044757/5da362b7-17ac-4575-b950-90fd6a9e8a19)

The client will take **2 parameters**
1. ther server PID (which was displayed after the launch of the server).
2. A string to send to the server.

![image](https://github.com/luyuyang6636/minitalk/assets/78044757/8d4bd1b5-0b48-493b-8b9f-b6398151e03f)


### Functionality
- The client must **send the string** passed as a parameter to the server. Once the string has been received, **the server must print it**.
- The server will be able to receive strings from several clients in a row without needing to restart.
- The communication between the client and the server has to be done only using two UNIX signals: `SIGUSR1` and `SIGUSR2`.
- The server acknowledges every message received by sending back a signal to the client.


### How to run?
Simply git clone the repository, enter the folder, and use the command `make` to compile both the server and client programs. As suggested by the description above, the server should be started first to we can get the PID as one of the arguments to start the client program. :)

### Key concepts practiced
In this project, I mainly explored the topic of **signals** and **bitwise operators**. Here are some useful (but rough) notes I made along the way, to get a foot into the world of handling signals:

* **Sigaction** - used for handling signals, the structure sigaction is used to specify how a signal should be handled, and the function is used to change the action associate with a signal.
  * **Structure**
    * `void (*sa_handler)(int)` - function to handle the signal
    * `void (*sa_sigaction)(int, siginfo_t *, void *)` - an alternate signal handler that provides more information about the signal. If sa_sigaction is specified, it takes precedence over sa_handler
    * `sigset_t sa_mask` - a set of signals that are blocked during the execution of signal handler. This prevents some signals from interrupting the signal handler itself
    * `Int sa_flags` - flags that modify the behaviour of a signal, such as SA_RESTART (cause certain system calls to be restarted if interrupted by the signal), and SA_SIGINFO (indicates the use of the sa_sigaction handler)
    * `void (*sa_restorer)(void)` - reserved for future use, not used on all systems. 
  * **Function** `int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact)`
    * `int signum` - the signal number for which the action is being set or retrieved (just the signal name such as SIGINT or SIGUSR1
    * `const struct sigaction *act` - a pointer to a sigaction structure that specifies the new action to be taken for the signal
    * `struct sigaction *oldact` - a pointer to a sigaction structure where previous action for the signal will be stored (if not NULL)
    * `return value` - -1 for unsuccessful completion, 0 for successful completion, errno should be set to indicate the error.

