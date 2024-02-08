#include "Yubaba.h"
Yubaba::Yubaba() {}

Yubaba::Yubaba(std::vector<Paint> textures) {
	this->textures = textures;
	currentTexture = textures[0].texture;
}

void Yubaba::animateLeft() {
	for (int i = 0; i < textures.size(); i++) {
		if (textures[i].isLeftTexture) {
			currentTexture = textures[i];
		}
	}
}

void Yubaba::animateRight() {
	for (int i = 0; i < textures.size(); i++) {
		if (textures[i].isRightTexture) {
			currentTexture = textures[i];
		}
	}
}