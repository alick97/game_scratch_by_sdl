#ifndef __LAYER_H__
#define __LAYER_H__

class Level;

class Layer {
public:
    virtual void render() = 0;
    virtual void update(Level *pLevel) = 0;
    virtual ~Layer() {}
};

#endif  /* defined(__LAYER_H__) */
