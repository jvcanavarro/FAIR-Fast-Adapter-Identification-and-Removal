import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


columns = ['plen8', 'plen16', 'plen32', 'plen64']
algorithms = open('algorithms.txt', 'r').read().splitlines()
data = pd.read_csv('all8-64.csv', names=columns, sep='\t', lineterminator='\n')


# data['mean'] = data[['plen8', 'plen16']].mean(axis=1)
data['mean'] = data.mean(axis=1)
top5 = data.sort_values('mean').head(5)

algorithms = open('algorithms.txt', 'r').read().splitlines()

top5_algos = [algorithms[i] for i in top5.index]
print(top5_algos)
# top5.index.names = [1, 2, 3, 4, 5]
x = top5.index.values
x = top5_algos
# print(type(top5.index))
# top5.reindex(top5_algos, copy=False, axis=0)
# top5.insert(loc=0, column='Algorithm', value=top5_algos)
# for i in top5.index:
# 	print(i)
# print(top5)

plt.rc('axes', axisbelow=True)

top5.plot.bar(title='Best 5 by Mean', cmap='plasma')
plt.xticks(np.arange(5), top5_algos, rotation=0)
plt.savefig('best5.png')
fig, axs = plt.subplots(2, 2)

top5['plen8'].plot.bar(ax=axs[0,0], color='yellow')
top5['plen32'].plot.bar(ax=axs[1,0], color='yellow')
top5['plen16'].plot.bar(ax=axs[0,1], color='yellow')
top5['plen64'].plot.bar(ax=axs[1,1], color='yellow')

# plt.xticks(np.arange(5), top5_algos)
axs[0,0].set_xticks(np.arange(5), top5_algos)

# axs[1,1].set_xticks(np.arange(5), columns)



for ax in axs.flat:
	ax.set_xticks(np.arange(5), top5_algos)
	ax.set(xlabel='Algorithms', ylabel='Time(s)')
	ax.label_outer()
# Hide x labels and tick labels for top plots and y ticks for right plots.
plt.show()
# axs[0, 0].plot(x, y)
# axs[0, 0].set_title('Axis [0,0]')
# axs[0, 1].plot(x, y, 'tab:orange')
# axs[0, 1].set_title('Axis [0,1]')
# axs[1, 0].plot(x, -y, 'tab:green')
# axs[1, 0].set_title('Axis [1,0]')
# axs[1, 1].plot(x, -y, 'tab:red')
# axs[1, 1].set_title('Axis [1,1]')

# for ax in axs.flat:
#     ax.set(xlabel='x-label', ylabel='y-label')

# # Hide x labels and tick labels for top plots and y ticks for right plots.
# for ax in axs.flat:
#     ax.label_outer()
