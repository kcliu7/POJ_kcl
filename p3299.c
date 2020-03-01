#include<stdio.h>
#include<math.h>

float getHumidex(float temperature, float dewpoint)
{
	float humidex, h, e;
	e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
	h = 0.5555 * (e - 10.0);
	humidex = temperature + h;
	return humidex;
}

float getTemperature(float dewpoint, float humidex)
{
	float temperature, h, e;
	e = 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
	h = 0.5555 * (e - 10.0);
	temperature = humidex - h;
	return temperature;
}

float getDewpoint(float temperature, float humidex)
{
    float dewpoint, e, h;
    h = humidex - temperature;
    e = h / 0.5555 + 10.0;
    dewpoint = 1 / ((1 / 273.16) - log(e / 6.11) / 5417.7530) - 273.16;
    return dewpoint;
}


void calculate(float *temperature, float *dewpoint, float *humidex, int digit)
{
    switch (digit)
    {
    case 3:
        *temperature = getTemperature(*dewpoint, *humidex);
        break;
    case 5:
        *dewpoint = getDewpoint(*temperature, *humidex);
        break;
    case 6:
        *humidex = getHumidex(*temperature, *dewpoint);
        break;
    }
}

int main()
{
	float t, d, h, tmp;
	char c[2];
	int count = 0;
	int digit = 0;
	scanf("%s", c);
	while (c[0] != 'E') {
		scanf("%f", &tmp);
		if (c[0] == 'T') {
			t = tmp;
			digit += 4;
		} else if (c[0] == 'D') {
			d = tmp;
			digit += 2;
		} else if (c[0] == 'H') {
			h = tmp;
			digit += 1;
		}
		count = (count + 1) % 2;
		if (count == 0) {
			calculate(&t, &d, &h, digit);
			digit = 0;
			printf("T %.1f D %.1f H %.1f\n", t, d, h);
		}
		scanf("%s", c);
	}
	
	return 0;
}