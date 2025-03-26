#pragma once


struct VengeanceVec2f
{
	float x;
	float y;

	VengeanceVec2f operator+(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x + vec2.x, y + vec2.y);
	}

	VengeanceVec2f operator-(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x - vec2.x, y - vec2.y);
	}

	VengeanceVec2f operator*(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x * vec2.x, y * vec2.y);
	}
};

struct VengeanceVec2i
{
	int x;
	int y;

	VengeanceVec2f operator+(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x + vec2.x, y + vec2.y);
	}

	VengeanceVec2f operator-(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x - vec2.x, y - vec2.y);
	}

	VengeanceVec2f operator*(const VengeanceVec2f& vec2)
	{
		return VengeanceVec2f(x * vec2.x, y * vec2.y);
	}
};