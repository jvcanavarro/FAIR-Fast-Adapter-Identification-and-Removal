import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


columns = ['plen8', 'plen16', 'plen32', 'plen64']

data = pd.read_csv('all8-64.csv', names=columns, sep='\t', lineterminator='\n')


data['mean'] = data[['plen32', 'plen64']].mean(axis=1)

top5 = data.sort_values('mean').head(5)


algo_names = open('algorithms.txt', 'r').read().splitlines()

top5_algos = [algo_names[i] for i in set(top5.index)]
print(top5)
print(top5_algos)


plt.rc('axes', axisbelow=True)

ax = top5.plot.bar(title='Best 5 by Mean', cmap='plasma')
plt.xticks(np.arange(5), top5_algos)
plt.figure()
top5['mean'].plot.bar(title='Sorted Means', cmap='plasma', width=0.3)
plt.xticks(np.arange(5), top5_algos)
plt.grid(linestyle=':')
plt.show()