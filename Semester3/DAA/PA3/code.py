import pandas as pd

def insertionSort(data):
	'''
	Objective : To sort the data citywise using insertion sort
	Input Value: List of [index, city] sorted on time
	Output Value: List of [index, city] sorted on city, time
	'''
	for i in range(1, len(data)):
		key = data[i][1]
		j = i-1
		value = data[i]
		while (j >= 0 and data[j][1] > key):
			data[j+1] = data[j]
			j = j-1

		data[j+1] = value

	return data

def main():
	# reading unsorted data from csv file
	data_unsorted = pd.read_csv('data_unsorted.csv')

	# creating unsorted index table from unsorted data
	indexTable_unsorted = data_unsorted[['index', 'city']]

	# Saving unsorted index table to csv file
	pd.DataFrame(indexTable_unsorted).set_index('index').to_csv('indexTable_unsorted.csv')

	# sorting unsorted index table on the basis of city using insertion sort
	sorted_indices = insertionSort(indexTable_unsorted.values.tolist())

	# creating dataframe for sorted indices
	indexTable_sorted = pd.DataFrame(sorted_indices, columns = ['index','city'])

	# saving sorted index table to csv file
	indexTable_sorted.set_index('index').to_csv('indexTable_sorted.csv')

	# arranging the unsorted data in sorted order using sorted index table
	data_sorted = data_unsorted.set_index('index').loc[indexTable_sorted['index'].tolist()]

	# saving the sorted data to csv file
	data_sorted.to_csv('data_sorted.csv')

if __name__=='__main__':
	main()