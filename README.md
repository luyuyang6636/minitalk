# MINITALK
### A communication program

In this program, I wrote code for 2 programs - **server** and **client**.

The server must be started first. After launch it will display its PID like this:

The client will take **2 parameters**
1. ther server PID (which was displayed after the launch of the server).
2. A string to send to the server.

### Functionality
- The client must **send the string** passed as a parameter to the server. Once the string has been received, **the server must print it**.
- The server will be able to receive strings from several clients in a row without needing to restart.
- The communication between the client and the server has to be done only using two UNIX signals: `SIGUSR1` and `SIGUSR2`.

