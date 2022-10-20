//Date: 26th Oct 2021
using System;
using System.Runtime.InteropServices;
using AutomationServerTypeLibForDotNet64Bit; //if 64-bit client exe is to be made
//using AutomationServerTypeLibForDotNet32Bit; //if 32-bit client exe is to be made

public class CSharpAutomationClient
{
    public static void Main()
    {
        //code
        CMyMathClass objCMyMathClass = new CMyMathClass();
        IMyMath objIMyMath = (IMyMath)objCMyMathClass;

        int num1 = 3, num2 = 2, sum, sub;

        sum = objIMyMath.SumOfTwoIntegers(num1, num2);
        Console.WriteLine("Sum of " + num1 + " & " + num2 + " is " + sum);

        sub = objIMyMath.SubtractionOfTwoIntegers(num1, num2);
        Console.WriteLine("Subtraction of " + num1 + " & " + num2 + " is " + sub);

    }
}

//To generate & import interop DotNet DLL from .tlb
//For 32-bit
//tlbimp.exe C:\Windows\SysWOW64\AutomationServerTypeLib.tlb /OUT:.\AutomationServerTypeLibForDotNet32bit.dll

//For 64-bit
//tlbimp.exe C:\Windows\System32\AutomationServerTypeLib.tlb /OUT:.\AutomationServerTypeLibForDotNet64Bit.dll

//Cmd to compile & create exe
//For 32-bit
//csc.exe /r:AutomationServerTypeLibForDotNet32Bit.dll CSharpAutomationClient.cs
//csc -platform:x86 -r:AutomationServerTypeLibForDotNet32Bit.dll CSharpAutomationClient.cs

//For 64-bit
//csc.exe /r:AutomationServerTypeLibForDotNet64Bit.dll CSharpAutomationClient.cs
//csc -r:AutomationServerTypeLibForDotNet64Bit.dll CSharpAutomationClient.cs

//To see the dll
//ildasm /classlist AutomationServerTypeLibForDotNet.dll > .\Temp.txt