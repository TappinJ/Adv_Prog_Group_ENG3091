import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from mpl_toolkits.mplot3d import Axes3D

eq_data = pd.read_csv('SLR_results_equation.csv')
grad_data = pd.read_csv('SLR_results_gradient.csv')
mlr_data = pd.read_csv('MLR_results.csv')

eq_data = pd.read_csv('SLR_results_equation.csv', skipinitialspace=True)
grad_data = pd.read_csv('SLR_results_gradient.csv', skipinitialspace=True)
mlr_data = pd.read_csv('MLR_results.csv', skipinitialspace=True)

# ===== PLOT 1 =====
# SLR
fig1 = plt.figure(figsize=(14,6))

# Subplot 1 --- SLR Equation
ax1 = fig1.add_subplot(121)
ax1.scatter(eq_data['x'], eq_data['y_actual'], color = 'green', label = 'Raw Data')
ax1.plot(eq_data['x'], eq_data['y_predicted'], color = 'green', label = 'Analytical Line')
ax1.set_title('SLR Equation Method')
ax1.set_xlabel('Independent variable (x)')
ax1.set_ylabel('Dependent variable (y)')
ax1.legend()
ax1.grid(True)

# Subplot 2 --- SLR Gradient
ax2 = fig1.add_subplot(122)
ax2.scatter(grad_data['x'], grad_data['y_actual'], label = 'Raw Data')
ax2.plot(grad_data['x'], grad_data['y_predicted'], label = 'Iterative Line')
ax2.set_title('SLR Gradient Method')
ax2.set_xlabel('Independent variable (x)')
ax2.set_ylabel('Independent variable (y)')
ax2.legend()
ax2.grid(True)

# ===== PLOT 2 =====
# MLR - 3D Plot
fig2 = plt.figure(figsize=(10,8))
ax3 = fig2.add_subplot(111, projection='3d')
# Raw data - scattered
ax3.scatter(mlr_data['x1'], mlr_data['x2'], mlr_data['y_actual'], color='red', label = 'Raw Data')
# Predicted Plane
ax3.plot_trisurf(mlr_data['x1'], mlr_data['x2'], mlr_data['y_predicted'], color='blue', alpha=0.4)

ax3.set_title('MLR: 3D Regression Plane')
ax3.set_xlabel('Feature 1 (x1)')
ax3.set_ylabel('Feature 2 (x2)')
ax3.set_zlabel('Target (y)')

red_patch = mpatches.Patch(color='red', label = 'Raw data')
blue_patch = mpatches.Patch(color='blue', label = 'Regression plane')
ax3.legend(handles=[red_patch, blue_patch])

plt.show()