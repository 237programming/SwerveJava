package org.usfirst.frc.team237.robot.math;

public class Vector {
	
	double x;
	double y;
	
	public Vector(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public void add(Vector other) {
		this.x += other.x;
		this.y += other.y;
	}
	
	public void subtract(Vector other) {
		this.x -= other.x;
		this.y -= other.y;
	}
	
	public void scale(double s) {
		this.x *= s;
		this.y *= s;
	}
	public void vectorNormalize() {
		double magnitude = this.vectorMagnitude();
		if (magnitude > 0.0) {
			x /= magnitude;
			y /= magnitude;
		}
	}
	public double vectorMagnitude() {
		return Math.sqrt(this.x*this.x + this.y*this.y);
	}
	
	public double vectorAngle()
	{
		return Math.atan2(this.x, this.y) * 180.0 / Math.PI;
	}
	public Vector vectorRotate(double angle){
		double ca = Math.cos(angle * Math.PI / 180.0);
		double sa = Math.sin(angle * Math.PI / 180.0);
		double x = ca * this.x - sa * this.y;
		double y = sa * this.x + ca * this.y; 
		Vector res = new Vector(x,y); 
		return res;
	}
	public double vectorDot(Vector v2) {
		return this.x * v2.x + this.y * v2.y;
	}
	
	public Vector vectorFromPolar(double azimuth, double radius){
		Vector v = new Vector(radius * Math.cos(azimuth * Math.PI / 180.0),(radius * Math.sin(azimuth * Math.PI / 180.0)));
		return v;
	}
	@Override
	public String toString() {
		return "(" + this.x + ", " + this.y + ")";
	}
}
