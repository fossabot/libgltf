#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stddef.h>

/*!
 * struct: SGlTFProperty
 */
struct SGlTFProperty
{
    SGlTFProperty();

    std::shared_ptr<struct SExtras> extras;
    std::shared_ptr<struct SExtension> extensions;
};

/*!
 * struct: SGlTFChildofRootProperty
 */
struct SGlTFChildofRootProperty : SGlTFProperty
{
    SGlTFChildofRootProperty();

    // The user-defined name of this object.
    string name;
};
/*!
 * struct: SMaterial
 * The material appearance of a primitive.
 */
struct SMaterial : SGlTFChildofRootProperty
{
    SMaterial();

    // The alpha cutoff value of the material.
    float alphaCutoff;
    // The emissive map texture.
    std::shared_ptr<struct STextureInfo> emissiveTexture;
    // A set of parameter values that are used to define the metallic-roughness material model from Physically-Based Rendering (PBR) methodology. When not specified, all the default values of `pbrMetallicRoughness` apply.
    std::shared_ptr<struct SMaterialPBRMetallicRoughness> pbrMetallicRoughness;
    // The occlusion map texture.
    std::shared_ptr<struct SMaterialOcclusionTextureInfo> occlusionTexture;
    // The alpha rendering mode of the material.
    string alphaMode;
    // Specifies whether the material is double sided.
    bool doubleSided;
    // The normal map texture.
    std::shared_ptr<struct SMaterialNormalTextureInfo> normalTexture;
    // The emissive color of the material.
    std::vector<float> emissiveFactor;
};

/*!
 * struct: SAsset
 * Metadata about the glTF asset.
 */
struct SAsset : SGlTFProperty
{
    SAsset();

    // The minimum glTF version that this asset targets.
    string minVersion;
    // The glTF version that this asset targets.
    string version;
    // Tool that generated this glTF model.  Useful for debugging.
    string generator;
    // A copyright message suitable for display to credit the content creator.
    string copyright;
};

/*!
 * struct: SSampler
 * Texture sampler properties for filtering and wrapping modes.
 */
struct SSampler : SGlTFChildofRootProperty
{
    SSampler();

    // s wrapping mode.
    int32_t wrapS;
    // Minification filter.
    int32_t minFilter;
    // Magnification filter.
    int32_t magFilter;
    // t wrapping mode.
    int32_t wrapT;
};

/*!
 * struct: SAnimationSampler
 * Combines input and output accessors with an interpolation algorithm to define a keyframe graph (but not its target).
 */
struct SAnimationSampler : SGlTFProperty
{
    SAnimationSampler();

    // The index of an accessor containing keyframe input values, e.g., time.
    int32_t input;
    // The index of an accessor, containing keyframe output values.
    int32_t output;
    // Interpolation algorithm.
    string interpolation;
};

/*!
 * struct: SExtras
 * Application-specific data.
 */
struct SExtras
{
    SExtras();

};

/*!
 * struct: SScene
 * The root nodes of a scene.
 */
struct SScene : SGlTFChildofRootProperty
{
    SScene();

    // The indices of each root node.
    std::vector<int32_t> nodes;
};

/*!
 * struct: SCameraPerspective
 * A perspective camera containing properties to create a perspective projection matrix.
 */
struct SCameraPerspective : SGlTFProperty
{
    SCameraPerspective();

    // The floating-point aspect ratio of the field of view.
    float aspectRatio;
    // The floating-point vertical field of view in radians.
    float yfov;
    // The floating-point distance to the near clipping plane.
    float znear;
    // The floating-point distance to the far clipping plane.
    float zfar;
};

/*!
 * struct: SBufferView
 * A view into a buffer generally representing a subset of the buffer.
 */
struct SBufferView : SGlTFChildofRootProperty
{
    SBufferView();

    // The length of the bufferView in bytes.
    int32_t byteLength;
    // The index of the buffer.
    int32_t buffer;
    // The offset into the buffer in bytes.
    int32_t byteOffset;
    // The target that the GPU buffer should be bound to.
    int32_t target;
    // The stride, in bytes.
    int32_t byteStride;
};

/*!
 * struct: STextureInfo
 * Reference to a texture.
 */
struct STextureInfo : SGlTFProperty
{
    STextureInfo();

    // The index of the texture.
    int32_t index;
    // The set index of texture's TEXCOORD attribute used for texture coordinate mapping.
    int32_t texCoord;
};
/*!
 * struct: SMaterialNormalTextureInfo
 */
struct SMaterialNormalTextureInfo : STextureInfo
{
    SMaterialNormalTextureInfo();

    // The scalar multiplier applied to each normal vector of the normal texture.
    float scale;
};

/*!
 * struct: SMaterialOcclusionTextureInfo
 */
struct SMaterialOcclusionTextureInfo : STextureInfo
{
    SMaterialOcclusionTextureInfo();

    // A scalar multiplier controlling the amount of occlusion applied.
    float strength;
};

/*!
 * struct: SAccessorSparseValues
 * Array of size `accessor.sparse.count` times number of components storing the displaced accessor attributes pointed by `accessor.sparse.indices`.
 */
struct SAccessorSparseValues : SGlTFProperty
{
    SAccessorSparseValues();

    // The index of the bufferView with sparse values. Referenced bufferView can't have ARRAY_BUFFER or ELEMENT_ARRAY_BUFFER target.
    int32_t bufferView;
    // The offset relative to the start of the bufferView in bytes. Must be aligned.
    int32_t byteOffset;
};

/*!
 * struct: SAnimationChannelTarget
 * The index of the node and TRS property that an animation channel targets.
 */
struct SAnimationChannelTarget : SGlTFProperty
{
    SAnimationChannelTarget();

    // The index of the node to target.
    int32_t node;
    // The name of the node's TRS property to modify, or the "weights" of the Morph Targets it instantiates.
    string path;
};

/*!
 * struct: SMesh
 * A set of primitives to be rendered.  A node can contain one mesh.  A node's transform places the mesh in the scene.
 */
struct SMesh : SGlTFChildofRootProperty
{
    SMesh();

    // An array of primitives, each defining geometry to be rendered with a material.
    std::vector<std::shared_ptr<struct SMeshPrimitive>> primitives;
    // Array of weights to be applied to the Morph Targets.
    std::vector<float> weights;
};

/*!
 * struct: SAccessorSparse
 * Sparse storage of attributes that deviate from their initialization value.
 */
struct SAccessorSparse : SGlTFProperty
{
    SAccessorSparse();

    // Number of entries stored in the sparse array.
    int32_t count;
    // Index array of size `count` that points to those accessor attributes that deviate from their initialization value. Indices must strictly increase.
    std::shared_ptr<struct SAccessorSparseIndices> indices;
    // Array of size `count` times number of components, storing the displaced accessor attributes pointed by `indices`. Substituted values must have the same `componentType` and number of components as the base accessor.
    std::shared_ptr<struct SAccessorSparseValues> values;
};

/*!
 * struct: SMeshPrimitive
 * Geometry to be rendered with the given material.
 */
struct SMeshPrimitive : SGlTFProperty
{
    SMeshPrimitive();

    // The index of the accessor that contains the indices.
    int32_t indices;
    // A dictionary object, where each key corresponds to mesh attribute semantic and each value is the index of the accessor containing attribute's data.
    int32_t attributes;
    // The index of the material to apply to this primitive when rendering.
    int32_t material;
    // The type of primitives to render.
    int32_t mode;
    // An array of Morph Targets, each  Morph Target is a dictionary mapping attributes (only `POSITION`, `NORMAL`, and `TANGENT` supported) to their deviations in the Morph Target.
    std::vector<int32_t> targets;
};

/*!
 * struct: SExtension
 * Dictionary object with extension-specific objects.
 */
struct SExtension
{
    SExtension();

};

/*!
 * struct: SAnimationChannel
 * Targets an animation's sampler at a node's property.
 */
struct SAnimationChannel : SGlTFProperty
{
    SAnimationChannel();

    // The index of the node and TRS property to target.
    std::shared_ptr<struct SAnimationChannelTarget> target;
    // The index of a sampler in this animation used to compute the value for the target.
    int32_t sampler;
};


/*!
 * struct: SAccessorSparseIndices
 * Indices of those attributes that deviate from their initialization value.
 */
struct SAccessorSparseIndices : SGlTFProperty
{
    SAccessorSparseIndices();

    // The indices data type.
    int32_t componentType;
    // The index of the bufferView with sparse indices. Referenced bufferView can't have ARRAY_BUFFER or ELEMENT_ARRAY_BUFFER target.
    int32_t bufferView;
    // The offset relative to the start of the bufferView in bytes. Must be aligned.
    int32_t byteOffset;
};

/*!
 * struct: SNode
 * A node in the node hierarchy.  When the node contains `skin`, all `mesh.primitives` must contain `JOINTS_0` and `WEIGHTS_0` attributes.  A node can have either a `matrix` or any combination of `translation`/`rotation`/`scale` (TRS) properties. TRS properties are converted to matrices and postmultiplied in the `T * R * S` order to compose the transformation matrix; first the scale is applied to the vertices, then the rotation, and then the translation. If none are provided, the transform is the identity. When a node is targeted for animation (referenced by an animation.channel.target), only TRS properties may be present; `matrix` will not be present.
 */
struct SNode : SGlTFChildofRootProperty
{
    SNode();

    // The node's non-uniform scale.
    std::vector<float> scale;
    // The node's unit quaternion rotation in the order (x, y, z, w), where w is the scalar.
    std::vector<float> rotation;
    // A floating-point 4x4 transformation matrix stored in column-major order.
    std::vector<float> matrix;
    // The index of the mesh in this node.
    int32_t mesh;
    // The index of the camera referenced by this node.
    int32_t camera;
    // The weights of the instantiated Morph Target. Number of elements must match number of Morph Targets of used mesh.
    std::vector<float> weights;
    // The index of the skin referenced by this node.
    int32_t skin;
    // The node's translation.
    std::vector<float> translation;
    // The indices of this node's children.
    std::vector<int32_t> children;
};

/*!
 * struct: SAnimation
 * A keyframe animation.
 */
struct SAnimation : SGlTFChildofRootProperty
{
    SAnimation();

    // An array of channels, each of which targets an animation's sampler at a node's property. Different channels of the same animation can't have equal targets.
    std::vector<std::shared_ptr<struct SAnimationChannel>> channels;
    // An array of samplers that combines input and output accessors with an interpolation algorithm to define a keyframe graph (but not its target).
    std::vector<std::shared_ptr<struct SAnimationSampler>> samplers;
};

/*!
 * struct: SSkin
 * Joints and matrices defining a skin.
 */
struct SSkin : SGlTFChildofRootProperty
{
    SSkin();

    // Indices of skeleton nodes, used as joints in this skin.
    std::vector<int32_t> joints;
    // The index of the accessor containing the floating-point 4x4 inverse-bind matrices.  The default is that each matrix is a 4x4 identity matrix, which implies that inverse-bind matrices were pre-applied.
    int32_t inverseBindMatrices;
    // The index of the node used as a skeleton root. When undefined, joints transforms resolve to scene root.
    int32_t skeleton;
};

/*!
 * struct: SMaterialPBRMetallicRoughness
 * A set of parameter values that are used to define the metallic-roughness material model from Physically-Based Rendering (PBR) methodology.
 */
struct SMaterialPBRMetallicRoughness : SGlTFProperty
{
    SMaterialPBRMetallicRoughness();

    // The roughness of the material.
    float roughnessFactor;
    // The base color texture.
    std::shared_ptr<struct STextureInfo> baseColorTexture;
    // The metalness of the material.
    float metallicFactor;
    // The material's base color factor.
    std::vector<float> baseColorFactor;
    // The metallic-roughness texture.
    std::shared_ptr<struct STextureInfo> metallicRoughnessTexture;
};

/*!
 * struct: SCamera
 * A camera's projection.  A node can reference a camera to apply a transform to place the camera in the scene.
 */
struct SCamera : SGlTFChildofRootProperty
{
    SCamera();

    // Specifies if the camera uses a perspective or orthographic projection.
    string type;
    // A perspective camera containing properties to create a perspective projection matrix.
    std::shared_ptr<struct SCameraPerspective> perspective;
    // An orthographic camera containing properties to create an orthographic projection matrix.
    std::shared_ptr<struct SCameraOrthographic> orthographic;
};

/*!
 * struct: SImage
 * Image data used to create a texture. Image can be referenced by URI or `bufferView` index. `mimeType` is required in the latter case.
 */
struct SImage : SGlTFChildofRootProperty
{
    SImage();

    // The image's MIME type.
    string mimeType;
    // The index of the bufferView that contains the image. Use this instead of the image's uri property.
    int32_t bufferView;
    // The uri of the image.
    string uri;
};

/*!
 * struct: STexture
 * A texture and its sampler.
 */
struct STexture : SGlTFChildofRootProperty
{
    STexture();

    // The index of the image used by this texture.
    int32_t source;
    // The index of the sampler used by this texture. When undefined, a sampler with repeat wrapping and auto filtering should be used.
    int32_t sampler;
};

/*!
 * struct: SCameraOrthographic
 * An orthographic camera containing properties to create an orthographic projection matrix.
 */
struct SCameraOrthographic : SGlTFProperty
{
    SCameraOrthographic();

    // The floating-point horizontal magnification of the view. Must not be zero.
    float xmag;
    // The floating-point vertical magnification of the view. Must not be zero.
    float ymag;
    // The floating-point distance to the far clipping plane. `zfar` must be greater than `znear`.
    float zfar;
    // The floating-point distance to the near clipping plane.
    float znear;
};

/*!
 * struct: SBuffer
 * A buffer points to binary geometry, animation, or skins.
 */
struct SBuffer : SGlTFChildofRootProperty
{
    SBuffer();

    // The length of the buffer in bytes.
    int32_t byteLength;
    // The uri of the buffer.
    string uri;
};

/*!
 * struct: SAccessor
 * A typed view into a bufferView.  A bufferView contains raw binary data.  An accessor provides a typed view into a bufferView or a subset of a bufferView similar to how WebGL's `vertexAttribPointer()` defines an attribute in a buffer.
 */
struct SAccessor : SGlTFChildofRootProperty
{
    SAccessor();

    // The number of attributes referenced by this accessor.
    int32_t count;
    // Minimum value of each component in this attribute.
    std::vector<float> min;
    // Maximum value of each component in this attribute.
    std::vector<float> max;
    // The index of the bufferView.
    int32_t bufferView;
    // The datatype of components in the attribute.
    int32_t componentType;
    // The offset relative to the start of the bufferView in bytes.
    int32_t byteOffset;
    // Sparse storage of attributes that deviate from their initialization value.
    std::shared_ptr<struct SAccessorSparse> sparse;
    // Specifies if the attribute is a scalar, vector, or matrix.
    string type;
    // Specifies whether integer data values should be normalized.
    bool normalized;
};

/*!
 * struct: SGlTF
 * The root object for a glTF asset.
 */
struct SGlTF : SGlTFProperty
{
    SGlTF();

    // An array of textures.
    std::vector<std::shared_ptr<struct STexture>> textures;
    // An array of cameras.
    std::vector<std::shared_ptr<struct SCamera>> cameras;
    // An array of accessors.
    std::vector<std::shared_ptr<struct SAccessor>> accessors;
    // Names of glTF extensions used somewhere in this asset.
    std::vector<string> extensionsUsed;
    // An array of samplers.
    std::vector<std::shared_ptr<struct SSampler>> samplers;
    // An array of scenes.
    std::vector<std::shared_ptr<struct SScene>> scenes;
    // The index of the default scene.
    int32_t scene;
    // Names of glTF extensions required to properly load this asset.
    std::vector<string> extensionsRequired;
    // An array of meshes.
    std::vector<std::shared_ptr<struct SMesh>> meshes;
    // An array of keyframe animations.
    std::vector<std::shared_ptr<struct SAnimation>> animations;
    // An array of images.
    std::vector<std::shared_ptr<struct SImage>> images;
    // An array of nodes.
    std::vector<std::shared_ptr<struct SNode>> nodes;
    // An array of bufferViews.
    std::vector<std::shared_ptr<struct SBufferView>> bufferViews;
    // An array of skins.
    std::vector<std::shared_ptr<struct SSkin>> skins;
    // An array of materials.
    std::vector<std::shared_ptr<struct SMaterial>> materials;
    // An array of buffers.
    std::vector<std::shared_ptr<struct SBuffer>> buffers;
    // Metadata about the glTF asset.
    std::shared_ptr<struct SAsset> asset;
};
