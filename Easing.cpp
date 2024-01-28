#define _USE_MATH_DEFINES
#include "Easing.h"
#include "Math.h"

namespace Easing {

	float	Lerp(float start, float end, float t)
	{
		return (1.0f - t) * start + end * t;
	}

	float Linear(float t, float totaltime, float min, float max)
	{
		return (max - min) * t / totaltime + min;
	}


	float InSine(float t, float totaltime, float min, float max) {
		if (t == 0.0f) return min;
		if (t == totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * (1.0f - cosf(t * (float)M_PI * 0.5f));
	}

	float OutSine(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * sinf(t * (float)M_PI * 0.5f);
	}

	float InOutSine(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * 0.5f * (1.0f - cosf(t * (float)M_PI));
	}


	float InQuad(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * t * t;
	}

	float OutQuad(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * (-t * (t - 2.0f));
	}

	float InOutQuad(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * t * t;
		}
		else {
			t -= 1.0f;
			return min + deltaValue * (-0.5f * (t * (t - 2.0f) - 1.0f));
		}
	}



	float InCubic(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * t * t * t;
	}

	float OutCubic(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		t -= 1.0f;
		return min + deltaValue * (t * t * t + 1.0f);
	}

	float InOutCubic(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * t * t * t;
		}
		else {
			t -= 2.0f;
			return min + deltaValue * 0.5f * (t * t * t + 2.0f);
		}
	}


	float InQuart(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * t * t * t * t;
	}

	float OutQuart(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		t -= 1.0f;
		return min + deltaValue * (1.0f - t * t * t * t);
	}

	float InOutQuart(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * t * t * t * t;
		}
		else {
			t -= 2.0f;
			return min + deltaValue * (-0.5f * (t * t * t * t - 2.0f));
		}
	}


	float InQuint(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * t * t * t * t * t;
	}

	float OutQuint(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		t -= 1.0f;
		return min + deltaValue * (1.0f + t * t * t * t * t);
	}

	float InOutQuint(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * t * t * t * t * t;
		}
		else {
			t -= 2.0f;
			return min + deltaValue * 0.5f * (t * t * t * t * t + 2.0f);
		}
	}


	float InExpo(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * powf(2.0f, 10.0f * (t - 1.0f));
	}

	float OutExpo(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * (-powf(2.0f, -10.0f * t) + 1.0f);
	}

	float InOutExpo(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * powf(2.0f, 10.0f * (t - 1.0f));
		}
		else {
			t -= 1.0f;
			return min + deltaValue * 0.5f * (-powf(2.0f, -10.0f * t) + 2.0f);
		}
	}


	float InCirc(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		return min + deltaValue * (1.0f - sqrtf(1.0f - t * t));
	}

	float OutCirc(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime;
		float deltaValue = max - min;

		t -= 1.0f;
		return min + deltaValue * sqrtf(1.0f - t * t);
	}

	float InOutCirc(float t, float totaltime, float min, float max) {
		if (t <= 0.0f) return min;
		if (t >= totaltime) return max;

		t /= totaltime * 0.5f;
		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * 0.5f * (1.0f - sqrtf(1.0f - t * t));
		}
		else {
			t -= 2.0f;
			return min + deltaValue * 0.5f * (sqrtf(1.0f - t * t) + 1.0f);
		}
	}


	float InBack(float t, float totaltime, float min, float max, float s)
	{
		s *= 1.70158f;
		max -= min;
		t /= totaltime;
		return max * t * t * ((s + 1) * t - s) + min;
	}

	float OutBack(float t, float totaltime, float min, float max, float s) {

		s *= 1.70158f;
		max -= min;
		t /= totaltime;

		t--;


		return max * (t * t * ((s + 1) * t + s) + 1) + min;
	}

	float InOutBack(float t, float totaltime, float min, float max, float s) {
		t /= totaltime;
		s *= 1.525f;
		max -= min;
		if ((t /= 0.5f) < 1) {
			return max / 2 * (t * t * ((s + 1) * t - s)) + min;
		}

		t -= 2;
		return max / 2 * (t * t * ((s + 1) * t + s) + 2) + min;
	}


	float InElastic(float t, float totaltime, float min, float max, float amplitude = 1.0f, float period = 0.3f) {
		if (t == 0.0f) return min;
		if (t == totaltime) return max;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime;

		float deltaValue = max - min;

		return min + deltaValue * (-amplitude * powf(2.0f, 10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period));
	}

	float OutElastic(float t, float totaltime, float min, float max, float amplitude = 1.0f, float period = 0.3f) {
		if (t == 0.0f) return min;
		if (t == totaltime) return max;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime;

		float deltaValue = max - min;

		return min + deltaValue * (amplitude * powf(2.0f, -10.0f * t) * sinf((t - s) * (2.0f * (float)M_PI) / period) + 1.0f);
	}

	float InOutElastic(float t, float totaltime, float min, float max, float amplitude = 1.0f, float period = 0.3f) {
		if (t == 0.0f) return min;
		if (t == totaltime) return max;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime * 0.5f;

		float deltaValue = max - min;

		if (t < 1.0f) {
			return min + deltaValue * (-0.5f * amplitude * powf(2.0f, 10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period));
		}
		else {
			return min + deltaValue * (amplitude * powf(2.0f, -10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period) * 0.5f + 1.0f);
		}
	}


	float InBounce(float t, float totaltime, float min, float max)
	{

		return max - OutBounce(totaltime - t, totaltime, max - min, 0) + min;
	}

	float OutBounce(float t, float totaltime, float min, float max)
	{
		max -= min;
		t /= totaltime;

		if (t < 1 / 2.75f)
			return max * (7.5625f * t * t) + min;
		else if (t < 2 / 2.75f)
		{
			t -= 1.5f / 2.75f;
			return max * (7.5625f * t * t + 0.75f) + min;
		}
		else if (t < 2.5f / 2.75f)
		{
			t -= 2.25f / 2.75f;
			return max * (7.5625f * t * t + 0.9375f) + min;
		}
		else
		{
			t -= 2.625f / 2.75f;
			return max * (7.5625f * t * t + 0.984375f) + min;
		}

	}

	float InOutBounce(float t, float totaltime, float min, float max)
	{

		if (t < totaltime / 2)
			return InBounce(t * 2, totaltime, max - min, max) * 0.5f + min;
		else
			return OutBounce(t * 2 - totaltime, totaltime, max - min, 0) * 0.5f + min + (max - min) * 0.5f;

	}


	float InElasticAmplitude(float t, float totaltime, float amplitude, float period) {
		if (t == 0.0f) return 0.0f;
		if (t == totaltime) return 1.0f;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime;

		return -amplitude * powf(2.0f, 10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period);
	}

	float OutElasticAmplitude(float t, float totaltime, float amplitude, float period) {
		if (t == 0.0f) return 0.0f;
		if (t == totaltime) return 1.0f;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime;

		return amplitude * powf(2.0f, -10.0f * t) * sinf((t - s) * (2.0f * (float)M_PI) / period) + 1.0f;
	}

	float InOutElasticAmplitude(float t, float totaltime, float amplitude, float period) {
		if (t == 0.0f) return 0.0f;
		if (t == totaltime) return 1.0f;

		float s = period / (2.0f * (float)M_PI) * asinf(1.0f);
		t /= totaltime * 0.5f;

		if (t < 1.0f) {
			return -0.5f * amplitude * powf(2.0f, 10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period);
		}
		else {
			return amplitude * powf(2.0f, -10.0f * (t - 1.0f)) * sinf((t - 1.0f - s) * (2.0f * (float)M_PI) / period) * 0.5f + 1.0f;
		}
	}







}