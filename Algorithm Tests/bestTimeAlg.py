#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np
import re
import math

def plotTopFive (x):
    plt.plot()
    plt.grid(linestyle = ':')
    plt.show()

def findBestMeans (x, plot = True):
    x = sorted(x, key=lambda x: x[1])

    x = x[:5]
    algo = [item[0] for item in x]
    time = [item[1] for item in x]

    y = np.arange(5)
    plt.bar(y, time, label = algo)
    plt.grid(True, linestyle = ':')
    plt.legend()
    plt.show()

    for i in range(5):
        print('Best Algos: %s (%.3f)' %(algo[i], time[i]))

def separeTime (uniqueTime):
    uniqueTime = [x for xs in uniqueTime for x in xs.split(' ')]
    uniqueTime = list(filter(None, uniqueTime))
    allTimes = [float(x[:-1]) for x in uniqueTime if re.match("^\d+?\.\d+?$", x)]
    return allTimes , uniqueTime[0], np.mean(allTimes)

def formatResults (arq):
    timeList = [line.split('\t') for line in arq.readlines()]
    formatedTimes = []
    x = 0
    for x in range(len(timeList)):
        timeList[x][-1] = timeList[x][-1].strip()
        formatedTimes.append(separeTime(timeList[x]))
    i = []
    formatedTimes = [i for i in formatedTimes if not math.isnan(i[2])]
    return formatedTimes

arq = open('all8-64.csv', 'r+')
x = formatResults(arq)


cutedALL = [y[1:] for y in x] # remove indivual times
findBestMeans(cutedALL)
