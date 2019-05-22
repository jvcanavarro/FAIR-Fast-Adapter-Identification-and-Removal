import pandas as pd

columns = ['Name', 'plen8', 'plen16', 'plen32', 'plen64']

data = pd.read_csv('all8-64.csv', names=columns, sep='\t', lineterminator='\n')
print(data.head())

