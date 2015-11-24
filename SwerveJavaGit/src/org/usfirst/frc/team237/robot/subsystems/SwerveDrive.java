package org.usfirst.frc.team237.robot.subsystems;
import org.usfirst.frc.team237.robot.math.Vector;
public class SwerveDrive 
{
	SwerveWheel[] wheels;
	Vector position;
	double rotation;
	//Init 
	public void initSwerveDrive()
	{
		this.position = new Vector(0.0,0.0);
		this.rotation = 0.0;
		
		this.wheels = new SwerveWheel[4];
		double scaleX = -1.0;
		double scaleY = 1.0;
		
		for (int i = 0; i < 4; i++ ){
			if (i == 0 || i == 2)
			{
				scaleX = -1.0;
			}
			else {
				scaleX = 1.0;
			} 
			if (i == 2 || i == 3)
			{
				scaleY = 1.0;
			}
			else {
				scaleY = -1.0;
			}
			this.wheels[i].direction = 1;
			this.wheels[i].rotation = 0.0;
			this.wheels[i].position = new Vector(scaleX*3.0 / 2.0, scaleY*3.0 / 2.0);
		}
	}
	
	public void updateSwerveRobot(double dt) 
	{
		int i; 
		Vector v1 = new Vector(0.0,0.0);
		Vector v2 = new Vector(0.0,0.0);
		
		for ( i = 0; i < 4; i++ )
		{
			this.wheels[i].updateWheel(dt);
			v1 = v1.vectorFromPolar(this.rotation + this.wheels[i].rotation, ROBOT_MAX_SPEED * this.wheels[i].direction * this.wheels[i].speed * dt);
			this.position.add(v1);
		}
		
		for ( i = 0; i < 4; i++ )
		{
			v1 = new Vector(-this.wheels[i].position.y, this.wheels[i].position.x);
			v1.vectorNormalize();
			
			v2 = v2.vectorFromPolar(this.wheels[i].rotation, this.wheels[i].speed);
			
			this.rotation +=
					ROBOT_MAX_ANGULAR_VELOCITY * v1.vectorDot(v2) * dt;
			
		}
	}
}