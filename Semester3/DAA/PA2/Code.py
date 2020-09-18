# data = [[Serial no. , Name, TimeStamp, Temp, Rainfall, Humidity]]

data = [[1, "Prayagraj", "00:00", 26, 50, 70],
        [2, "Varanasi", "00,30", 22, 23, 30],
        [3, "Delhi", "01:00", 30, 23, 20],
        [4, "Mumbai", "01:30", 25, 31, 31],
        [5, "Indore", "02:00", 19, 20, 21],
        [6, "Delhi", "02:30", 32, 50, 40],
        [7, "Prayagraj", "03:00", 32, 40, 60],
        [8, "Varanasi", "03:30", 21, 30, 45],
        [9, "Mumbai", "04:00", 20, 50, 65],
        [10, "Indore", "04:30", 18, 20, 31],
        [11, "Delhi", "05:00", 27, 22, 11],
        [12, "Prayagraj", "05:30", 26, 28, 38],
        [13, "Indore", "06:00", 20, 28, 21],
        [14, "Mumbai", "06:30", 21, 32, 38],
        [15, "Varanasi", "07:00", 21, 45, 55],
        [16, "Prayagraj", "07:30", 30, 90, 95],
        [17, "Delhi", "08:00", 22, 80, 96],
        [18, "Varanasi", "08:30", 25, 25, 21],
        [19, "Indore", "09:00", 20, 32, 31],
        [20, "Mumbai", "09:30", 21, 50, 55],
        [21, "Prayagraj", "10:00", 27, 87, 15],
        [22, "Delhi", "10:30", 27, 56, 20],
        [23, "Varanasi", "11:00", 22, 34, 25],
        [24, "Indore", "11:30", 21, 36, 30],
        [25, "Mumbai", "12:00", 23, 30, 35],
        [26, "Prayagraj", "12:30", 29, 41, 15],
        [27, "Indore", "13:00", 25, 51, 20],
        [28, "Varanasi", "13:30", 28, 32, 25],
        [29, "Delhi", "14:00", 31, 44, 30],
        [30, "Mumbai", "14:30", 21, 29, 35],
        [31, "Indore", "15:00", 28, 81, 15],
        [32, "Prayagraj", "15:30", 31, 91, 20],
        [33, "Varanasi", "16:00", 29, 20, 25],
        [34, "Delhi", "16:30", 32, 21, 30],
        [35, "Mumbai", "17:00", 26, 22, 30],
        [36, "Indore", "17:30", 26, 22, 15],
        [37, "Varanasi", "18:00", 25, 23, 20],
        [38, "Delhi", "18:30", 29, 24, 25],
        [39, "Prayagraj", "19:00", 28, 25, 30],
        [40, "Mumbai", "19:30", 19, 32, 40],
        [41, "Indore", "20:00", 23, 33, 15],
        [42, "Delhi", "20:30", 26, 66, 20],
        [43, "Prayagraj", "21:00", 27, 55, 25],
        [44, "Varanasi", "21:30", 22, 23, 30],
        [45, "Mumbai", "22:00", 29, 20, 25],
        [46, "Delhi", "22:30", 30, 23, 20],
        [47, "Prayagraj", "23:00", 28, 27, 36],
        [48, "Indore", "23:30", 19, 20, 21],
        [49, "Varanasi", "23:40", 31, 55, 44],
        [50, "Mumbai", "23:50", 21, 40, 50]]

# Function to sort the data using Insertion sort technique
def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i][1]
        j = i-1
        value = arr[i]
        while (j >= 0 and arr[j][1] > key):
            arr[j+1] = arr[j]
            j = j-1

        arr[j+1] = value


insertionSort(data)

print("Sorted data with respect to Cities:")
for entry in data:
    print(entry)

