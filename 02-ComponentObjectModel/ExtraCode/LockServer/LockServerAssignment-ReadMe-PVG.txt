LockServer() Assignment (Optional)
====================================

Server : Class Factory Server DLL (ClassFactoryDLLServerWithRegFile.cpp)
Client : Client Of Class Factory DLL (ClientOfClassFactoryDLLServerWithRegFile.cpp)

=============================================================================================================================
Please Note : 
a) All following steps are given in algorithm form which you have to convert into code.
b) These steps are only the additions to be made to you current exisiting codes and only for this LockServer() assignment.
=============================================================================================================================


In ClassFactoryDLLServerWithRegFile.cpp Source Code :
=======================================================

Give Message Boxes which will show the values of 'glNumberOfActiveComponents' and 'glNumberOfServerLocks' at the following
places atleast (you can also place more Message Boxes in other places in the code as well, it is entirely up to you) :

I]   Inside case 'DLL_PROCESS_ATTACH', before break-statement

II]  Inside case 'DLL_PROCESS_DETACH', before break-statement

III] Inside CreateInstance() :
     a. At the beginning - Just before if(pUnkOuter != NULL) and after variable declarations.
     b. At the end - Just before return(hr) and after pCSumSubtract->Release();

IV]  Inside LockServer() - Just before return(S_OK) and after if-else

V]   Inside DllCanUnloadNow(), before if-statement.

Remember to give the title text of each Message Box such that it will tell from where in the code the message box is coming from.
This is for your own understanding of how the code flows and how the values of 'glNumberOfActiveComponents' and
'glNumberOfServerLocks' keep changing throughout the code.

Compile and link the Server DLL Code and copy the newly created DLL to System32 or SysWOW64 directory.


=============================================================================================================================


In ClientOfClassFactoryDLLServerWithRegFile.cpp Source Code :
================================================================

1. Globally - declare an 'int' variable named : 'giFlag' and initialize it to 0.

2. Globally - declare interface pointer of IClassFactory (say, 'gpIClassFactory') and initialize it to NULL.

3. In WndProc(), change declaration of "HRESULT hr;" to "static HRESULT hr;"

4. In WndPoc(), inside case WM_CREATE :
   a. Call CoGetClassObject() as taught by Sir in CoCreateInstance() pseudo code. 
      In this call to CoGetClassObject(), obtain IClassFactory pointer in 'gpIClassFactory'.
   b. Perform necessary error checking on above obtained 'hr' to check success or failure of CoGetClassObject().
   c. If successful, call LockServer() on the above obtained IClassFactory pointer and pass 'TRUE' as parameter to it.

5. In WndProc(), add case WM_LBUTTONDOWN and inside it :
   a. Increment 'giFlag' by 1.
   b. If 'giFlag' value is 1, then => 
      - Call CreateInstance() on above obtained IClassFactory pointer and get ISum pointer.
      - Perform necessary error checking on above obtained 'hr' to check success or failure of CreateInstance().
      - If successful, call SumOfTwoIntegers() on above obtained ISum pointer and get the result.
      - Print the result in Message Box
      - Release ISum pointer and re-assign it to NULL.
      - You can give a Message Box upon successful release of ISum pointer.
   c. If 'giFlag' value is 2, then => 
      - Call CreateInstance() on above obtained IClassFactory pointer and get ISubtract pointer.
      - Perform necessary error checking on above obtained 'hr' to check success or failure of CreateInstance().
      - If successful, call SubtractionOfTwoIntegers() on above obtained ISubtract pointer and get the result.
      - Print the result in Message Box
      - Release ISubtract pointer and re-assign it to NULL.
      - You can give a Message Box upon successful release of ISubtract pointer.
   d. If 'giFlag' value is 3, then => Call DestroyWindow(hwnd);

6. In WndProc(), inside case WM_DESTROY (but before PostQuitMessage(0)), write code for :
   If gpIClassFactory != NULL, then =>
   - Call LockServer() on the IClassFactory pointer and pass 'FALSE' as parameter to it.
   - Release IClassFactory pointer and re-assign it to NULL.
   - You can give a Message Box upon successful release of IClassFactory pointer.

7. Let rest all code remain the same.

8. Compile, Link and Execute the client code and see all the message boxes from the server and client code appear.
   Note down the values of 'glNumberOfActiveComponents' and 'glNumberOfServerLocks' from each message box.
   Revise the code flow using these values.


=============================================================================================================================


   





