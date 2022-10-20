use Win32::OLE;

my $obj = Win32::OLE->new("{44EA501F-515E-4B8A-8786-238D4110A31E}");
#put CLSID of CoClass i.e MyMath from .h file 
#to create OLE Automation WIN32OLE object

my $num1 = 40;
my $num2 = 15;

#put your add & subtract func names
my $resultAddition = $obj->SumOfTwoIntegers($num1,$num2);
print "$num1 + $num2 = $resultAddition\n";

my $resultSubtraction = $obj->SubtractionOfTwoIntegers($num1,$num2);
print "$num1 - $num2 = $resultSubtraction\n";
