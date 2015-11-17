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
}