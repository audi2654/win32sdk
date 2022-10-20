import comtypes.client as cc
import comtypes

#put type lib LIBID (GUID) below from
tlb_id = comtypes.GUID("{F14C8E20-55B1-4F33-B518-B5E348534692}")

cc.GetModule((tlb_id, 1, 0))	#1 & 0 are major minor nos of our typelib

import comtypes.gen.AutomationServerWithRegFileTypeLib as AutomationServerTypeLib
#AutomationServerWithRegFileTypeLib is the type lib name you gave in IDL file

pIMyMath = cc.CreateObject("{44EA501F-515E-4B8A-8786-238D4110A31E}", None, None, AutomationServerTypeLib.IMyMath)
#put CLSID of CoClass MyMath from .h file & name of our type lib interface from above

result = pIMyMath.SumOfTwoIntegers(56,44)
print ("Sum of 56 & 44 is : ") + str(result)

print ("Requesting IMyMath using pIMyMath")
pIMyMath2 = pIMyMath.QueryInterface(AutomationServerTypeLib.IMyMath)

result2 = pIMyMath.SubtractionOfTwoIntegers(56,44)
print ("Sum of 56 & 44 is : ") + str(result2)