import matplotlib.pyplot as plt
x_values=[500, 1000, 1500, 2000, 2500, 3000, 3500]
time_values=[0.074,0.141,0.189,0.227,0.314,0.375,0.431] # in seconds
plt.plot(x_values, time_values, marker='o')
plt.title("Linear Search: Time vs Number of Elements")
plt.xlabel("Number of Elements (n)")
plt.ylabel("Time Taken (seconds)")
plt.grid(True)
plt.show() 