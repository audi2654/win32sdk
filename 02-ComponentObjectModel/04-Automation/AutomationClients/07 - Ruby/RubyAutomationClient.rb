require 'win32ole'

objMyMath = WIN32OLE.new('{44EA501F-515E-4B8A-8786-238D4110A31E}')
#put CLSID of CoClass MyMath here from .h file

num1 = 50
num2 = 17

#put your function names below
resultAddition = objMyMath.SumOfTwoIntegers(num1,num2)
puts "#{num1} + #{num2} = #{resultAddition}"

resultSubtraction = objMyMath.SubtractionOfTwoIntegers(num1,num2)
puts "#{num1} - #{num2} = #{resultSubtraction}"
