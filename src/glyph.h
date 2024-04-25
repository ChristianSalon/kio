/**
 * @file glyph.h
 * @author Christian Saloň
 */

#pragma once

#include <vector>
#include <cstdint>

#include <glm/vec2.hpp>

#include "text_renderer_utils.h"

namespace vft {

/**
 * @class Glyph
 *
 * @brief Represents glyph vertex data and metrics
 */
class Glyph {

private:

    std::vector<glm::vec2> _vertices;       /**< Glyph vertices */
    std::vector<uint32_t> _indices;         /**< Glyph vertex indices */
    std::vector<vft::edge_t> _edges;         /**< Glyph edges */

    /**
     * Indicates by how much to increment the X coordinate of pen position.
     * This includes the glyph's width plus the space behind.
     * Used for horizontal layouts
     */
    int _advanceX;

    /**
     * Indicates by how much to increment the Y coordinate of pen position.
     * Not specified for horizontal layouts
     */
    int _advanceY;

public:

    Glyph();

    void addVertex(glm::vec2 vertex);
    void updateVertex(int index, glm::vec2 vertex);

    void addEdge(vft::edge_t edge);
    void updateEdge(int index, vft::edge_t edge);

    void addIndex(uint32_t index);

    void setVertices(const std::vector<glm::vec2> &vertices);
    void setIndices(const std::vector<uint32_t> &indices);
    void setEdges(const std::vector<vft::edge_t> &edges);
    void setAdvanceX(int advanceX);
    void setAdvanceY(int advanceY);

    int getAdvanceX() const;
    int getAdvanceY() const;
    const std::vector<glm::vec2> &getVertices() const;
    const std::vector<uint32_t> &getIndices() const;
    const std::vector<vft::edge_t> &getEdges() const;
    int getVertexCount() const;
    int getIndexCount() const;
    int getEdgeCount() const;

};

}
