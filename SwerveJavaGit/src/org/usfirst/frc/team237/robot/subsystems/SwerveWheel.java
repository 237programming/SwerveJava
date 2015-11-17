package org.usfirst.frc.team237.robot.subsystems;
import org.usfirst.frc.team237.robot.math.Vector;

public class SwerveWheel 
{
	Vector position;
	double rotationSetpoint;
	double rotation;
	double speed;
	int direction;
	
	public void updateWheel(double dt)
	{
		/* Clamps the wheel speed between 1.0 and -1.0 */
		if (this.speed > 1.0) {
			this.speed = 1.0;
		}
		else if (this.speed < -1.0){
			this.speed = -1.0;
		}
		/* Applies a deadband speed and rotation */
		if (Math.abs(this.speed)< 0.1 || Math.abs(this.rotation) - this.rotationSetpoint < 5.0) {
			return;
		}
		
		double alpha = Math.pow(0.005, dt);
		this.rotation = alpha * this.rotation + (1.0 - alpha) * this.rotationSetpoint;
	}
}
