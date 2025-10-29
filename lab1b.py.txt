import matplotlib.pyplot as plt
x_values=[10,100,1000,5000,10000,50000]
time_values=[0.009000,0.030000,0.047000,0.090000,0.088000,0.092000] # in seconds
time_values=[0.000014,0.000029,0.000045,0.000066,0.000075,0.000083] # in seconds
plt.plot(x_values, time_values, marker='o')
plt.title("Linear Search: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show()