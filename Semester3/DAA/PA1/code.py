import matplotlib.pyplot as plt 
import numpy as np
import pandas as pd

n=[]

for i in range(10,101,5):
    n.append(i)
    
best_case=[]
average_case=[]
worst_case=[]
    
for size in n:
    arr=[];
    number_of_comprison=[];
    for i in range(1,size+1):
        arr.append(i)

    for key in range(1,size+2):
        count = 0;
        for i in arr:
            count+=1;
            if (i==key):
                break;
        number_of_comprison.append(count);
        
    best_case.append(number_of_comprison[0])
    average_case.append(sum(number_of_comprison)/(size+1))
    worst_case.append(number_of_comprison[size])

data = pd.DataFrame({
    "Size of array(n)":n,
    "Best case":best_case,
    "Average case":average_case,
    "Worst case":worst_case
})

data

plt.plot(n,best_case,color='green') 
plt.plot(n,average_case,color='blue')
plt.plot(n,worst_case,color='red') 
plt.xlim(0,100)
plt.ylim(0,100)
plt.ylabel('Number Of Comparisions') 
plt.xlabel('Size of Array') 
plt.legend(['Best case','Average case','Worst case'])
plt.show()