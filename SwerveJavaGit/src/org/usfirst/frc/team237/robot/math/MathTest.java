package org.usfirst.frc.team237.robot.math;

public class MathTest {
	public static void main(String[] args) {
		Vector vector1 = new Vector(3.0, -2.0);
		Vector vector2 = new Vector(-5.0, 1.0);
		
		System.out.println(vector1);
		
		//vector1.add(vector2);
		
		System.out.println(vector1);
		
		//vector1.scale(1000.0);
		Vector vec3 = vector1.vectorRotate(180.0);
		
		System.out.println(vec3);
		
	}
}
