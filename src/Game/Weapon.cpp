#include <string>
class Weapon
{
private:
	float fireRate;	// Bullets per second
	float reloadTime;  // Time in seconds to reload
	int ammo;
	int magazineCapacity;
	float damage;
public:
	Weapon(/* args */);
	~Weapon();

	virtual int getAmmoCount() const = 0;
	virtual void shoot() = 0;
	virtual void reload() = 0;
	virtual float getFireRate() const = 0;
	virtual float getReloadTime() const = 0;
	virtual std::string getWeaponName() const = 0;
};
