import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


columns = ['plen8', 'plen16', 'plen32', 'plen64']

data = pd.read_csv('all8-64.csv', names=columns, sep='\t', lineterminator='\n')
# print(data.iloc[:2])

data['means'] = data.mean(axis=1)
data['std'] = data.std(axis=1)
print(data.head(10))
top5 = data.sort_values('means').head(5)
print(top5)
print(top5.iloc[0, 0])


